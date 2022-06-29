#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"UI.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//�󂯎�����R���g���[���̊i�[
	controller = pController;
	//�v���C���[�𓮓I�m��
	player = new CPlayer(controller);
	//�A�b�v���}�l�[�W���[�𓮓I�m��
	applemanager = new CAppleManager();
	//UI�𓮓I�m��
	UI = new CUI(controller);
}

CGame::~CGame() {
	//���I�m�ۂ������̂��������
	delete player;
	delete applemanager;
	delete UI;
}

CScene* CGame::Update() {
	//�Q�[����(�������ԓ��A�|�[�Y���ł͂Ȃ�)�Ȃ�X�V����
	if (UI->Update()) {//�Q�[����(�������ԓ��A�|�[�Y���ł͂Ȃ�)���ǂ�����Ԃ�
		applemanager->Update();
		player->Update();
	}
	else if(!UI->GetisPause()) {
		//�������Ԑ؂�̎��A3�b��ɉ�ʑJ��
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