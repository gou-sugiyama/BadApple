#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {
	EndImage = LoadGraph("images/End.png");
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
	DrawGraph(0,0,EndImage, FALSE);
}