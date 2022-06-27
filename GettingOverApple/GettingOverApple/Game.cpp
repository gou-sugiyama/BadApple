#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"Player2.h"
#include"AppleManager.h"

CGame::CGame(CSceneManager* pManager) :CScene(pManager) { //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
	//�v���C���[�𓮓I�m��
	player = new CPlayer(pManager);
	//�A�b�v���}�l�[�W���[�𓮓I�m��
	applemanager = new CAppleManager();
}

CGame::~CGame() {
	//���I�m�ۂ������̂��������
	delete player;
	delete applemanager;
}

CScene* CGame::Update() {
	applemanager->Update();
	player->Update();

	return this;
}

void CGame::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255),"�Q�[��");
	applemanager->Render();
	player->Render();
}