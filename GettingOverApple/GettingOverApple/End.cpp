#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {

}

//--------------------------------
// �X�V
//--------------------------------
CScene* CEnd::Update() {
	//controller->control(false);
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CEnd::Render()const {
	DrawString(0, 0, "�G���h���", 0xFFFFFF);
}