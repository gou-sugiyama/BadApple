#include"DxLib.h"
#include"Manager.h"
#include"Game.h"
#include"Title.h"
#include"Player.h"

CGame::CGame(CManager* pManager) :CScene(pManager) { //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
	//�v���C���[�𓮓I�m��
	player = new CPlayer(pManager);
}

CGame::~CGame() {
	//���I�m�ۂ������̂��������
	delete player;
}

void CGame::Update() {
	player->Update();
}

void CGame::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255),"�Q�[��");
	player->Render();
}