#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "Help.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CHelp::CHelp(CController* pController) :CScene(pController) {

}

//--------------------------------
// �X�V
//--------------------------------
CScene* CHelp::Update() {
	//controller->control(false);
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CHelp::Render()const {
	DrawString(0, 0, "�w���v���", 0xFFFFFF);
}