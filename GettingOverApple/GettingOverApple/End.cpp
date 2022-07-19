#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {
	image = LoadGraph("images/haikei.png");
}

//--------------------------------
// �X�V
//--------------------------------
CScene* CEnd::Update() {
	static int limit = 180;

	if (limit-- < 0) {
		return nullptr;
	}
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CEnd::Render()const {
	DrawGraph(0, 0, image, FALSE);
}