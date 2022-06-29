#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"UI.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//受け取ったコントローラの格納
	controller = pController;
	//プレイヤーを動的確保
	player = new CPlayer(controller);
	//アップルマネージャーを動的確保
	applemanager = new CAppleManager();
	//UIを動的確保
	UI = new CUI(controller);
}

CGame::~CGame() {
	//動的確保したものを解放する
	delete player;
	delete applemanager;
	delete UI;
}

CScene* CGame::Update() {
	//ゲーム中(制限時間内、ポーズ中ではない)なら更新する
	if (UI->Update()) {//ゲーム中(制限時間内、ポーズ中ではない)かどうかを返す
		applemanager->Update();
		player->Update();
	}
	else if(!UI->GetisPause()) {
		//制限時間切れの時、3秒後に画面遷移
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			return nullptr;
		}
	}
	return this;
}

void CGame::Render()const {
	//DrawFormatString(0, 0, GetColor(255, 255, 255),"ゲーム");
	applemanager->Render();
	player->Render();
	UI->Render();
}