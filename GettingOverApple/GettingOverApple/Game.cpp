#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"UI.h"
#include"Hit.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//�󂯎�����R���g���[���̊i�[
	controller = pController;
	//�v���C���[�𓮓I�m��
	player = new CPlayer(controller);
	//�A�b�v���}�l�[�W���[�𓮓I�m��
	applemanager = new CAppleManager();
	//UI�𓮓I�m��
	UI = new CUI(controller);
	//Hit
	hit = new CHitBoxCheck;
}

CGame::~CGame() {
	//���I�m�ۂ������̂��������
	delete player;
	delete applemanager;
	delete UI;
	delete hit;
}

CScene* CGame::Update() {

	if (UI->Update()) {
		applemanager->Update();
		player->Update();
		if (hit->HitBox(player, applemanager->getpApple())
			&& applemanager->getpApple()->getisShow()) {
			applemanager->getpApple()->toggleisShow();

		}
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
	//DrawFormatString(0, 0, GetColor(255, 255, 255),"�Q�[��");
	applemanager->Render();
	player->Render();
	UI->Render();
}