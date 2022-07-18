#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Player.h"
#include"Ranking.h"
#include"AppleManager.h"
#include"UI.h"
#include"Controller.h"
#include"Object.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CGame::CGame(CController* pController):CScene(pController){ 
	//受け取ったコントローラの格納
	controller = pController;
	//プレイヤーを動的確保
	player = new CPlayer(controller);
	//アップルマネージャーを動的確保
	applemanager = new CAppleManager();
	//アップルマネージャーからリンゴを取得
	apple = applemanager->GetpApple();
	//UIを動的確保
	UI = new CUI(controller);
	//背景画像の読み込み
	image = LoadGraph("images/haikei.png");
}

//--------------------------------
// デストラクタ
//--------------------------------
CGame::~CGame() {
	//動的確保したものを解放する
	delete player;
	delete applemanager;
	delete UI;
}

//--------------------------------
// 更新
//--------------------------------
CScene* CGame::Update() {
	controller->Update();

	//ゲーム中(制限時間内、ポーズ中ではない)なら更新する
	if (UI->Update()) {//ゲーム中(制限時間内、ポーズ中ではない)かどうかを返す
		if (UI->GetisPause() != true) {
			applemanager->Update();
			player->Update();
			for (int i = 0; i < D_APPLE_MAX; i++) {
				if (CheckHit(&apple[i], player)) HitAction(&apple[i],player);
			}
		}
	}
	else {
		//制限時間切れの時、3秒後に画面遷移
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			return new CRanking(controller);
		}
	}
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CGame::Render()const {
	DrawGraph(0, 0, image, FALSE);
	applemanager->Render();
	player->Render();
	UI->Render();
}

//-----------------------
// 衝突処理
//-----------------------
void CGame::HitAction(CApple* apple, CPlayer* player) {
	UI->SetScore(apple->GetScore());
	UI->SetCount(apple->GetType());
}