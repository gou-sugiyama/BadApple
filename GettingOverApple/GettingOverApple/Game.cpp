#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"UI.h"

CGame::CGame(CSceneManager* pManager) :CScene(pManager) { //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
	//�v���C���[�𓮓I�m��
	player = new CPlayer(pManager);
	//�A�b�v���}�l�[�W���[�𓮓I�m��
	applemanager = new CAppleManager();
	//UI�𓮓I�m��
	UI = new CUI(pManager);
}

CGame::~CGame() {
	//���I�m�ۂ������̂��������
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
	DrawFormatString(0, 0, GetColor(255, 255, 255),"�Q�[��");
	applemanager->Render();
	player->Render();
	UI->Render();
}