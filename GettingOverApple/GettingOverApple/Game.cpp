#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"Ranking.h"
#include"UI.h"
#include"Hit.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//受け取ったコントローラの格納
	controller = pController;
	//プレイヤーを動的確保
	player = new CPlayer(controller);
	//アップルマネージャーを動的確保
	applemanager = new CAppleManager();
	//UIを動的確保
	UI = new CUI(controller);
	//Hit
	hit = new CHitBoxCheck;
}

CGame::~CGame() {
	//動的確保したものを解放する
	delete player;
	delete applemanager;
	delete UI;
	delete hit;
}

CScene* CGame::Update() {

	if (UI->Update()) {
		applemanager->Update();
		player->Update();
		if (hit->HitBox(player, applemanager->getpApple(0))
			&& applemanager->getpApple(0)->getisShow()) {
			applemanager->getpApple(0)->toggleisShow();

		}
	}
	else {
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			return new CRanking(controller);
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