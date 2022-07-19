#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"RankMng.h"
#include"UI.h"
#include"Hit.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//画像の格納
	image = LoadGraph("images/haikei.png");
	//受け取ったコントローラの格納
	controller = pController;
	//コントローラーのフラグを変更
	controller->ToggleControlFlg();		//フラグをFALSEへ変更
	//プレイヤーを動的確保
	player = new CPlayer(controller);
	//アップルマネージャーを動的確保
	appleManager = new CAppleManager();
	//アップルマネージャーからリンゴを取得
	apple = appleManager->GetpApple();
	//UIを動的確保
	UI = new CUI(controller);
	//Hit
	hit = new CHitBoxCheck;

	keyInput = controller->control(false);
}

CGame::~CGame() {
	//動的確保したものを解放する

	//コントローラーのフラグを変更
	controller->ToggleControlFlg();		//フラグをTRUEへ変更

	delete player;
	delete appleManager;
	delete UI;
	delete hit;
}

CScene* CGame::Update() {
	keyInput = controller->control(false);
	//ゲーム中(制限時間内、ポーズ中ではない)なら更新する
	if (UI->Update()) {//ゲーム中(制限時間内、ポーズ中ではない)かどうかを返す
		if (UI->GetisPause() != true) {
			appleManager->Update();
			player->Update();
			for (int i = 0; i < D_APPLE_MAX; i++) {
				if (player->GetTnos() <= 0 && hit->HitBox(player, &apple[i])) {
					UI->SetCount(apple[i].GetType());
					UI->SetScore(apple[i].GetScore());
				}

			}
		}
	}
	else {
		//制限時間切れの時、3秒後に画面遷移
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			controller->SetScore(UI->GetScore());
			return new CRankMng(controller);
			rankmng->SetScore(UI->GetScore());
		}
	}
	return this;
}

void CGame::Render()const {
	DrawGraph(0, 0, image, FALSE);
	appleManager->Render();
	player->Render();
	UI->Render();
}