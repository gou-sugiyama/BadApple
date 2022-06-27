#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"UI.h"

CGame::CGame(CSceneManager* pManager) :CScene(pManager) { //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
	//プレイヤーを動的確保
	player = new CPlayer(pManager);
	//アップルマネージャーを動的確保
	applemanager = new CAppleManager();
	//UIを動的確保
	UI = new CUI(pManager);
}

CGame::~CGame() {
	//動的確保したものを解放する
	delete player;
	delete applemanager;
}

CScene* CGame::Update() {

	if (UI->Update()) {
		applemanager->Update();
		player->Update();
	}
	else {
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			return nullptr;
		}
		
	}

	return this;
}

void CGame::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255),"ゲーム");
	applemanager->Render();
	player->Render();
	UI->Render();
}