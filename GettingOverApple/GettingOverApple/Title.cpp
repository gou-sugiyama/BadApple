#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Controller.h"
#include"Game.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CTitle::CTitle(CController* pController) :CScene(pController) {

}

//--------------------------------
// �X�V
//--------------------------------
CScene* CTitle::Update() {
	if (controller->control(false).Buttons[4]) {
		//�Q�[���V�[���Ɉڍs
		return new CGame(controller);
	}
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CTitle::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�^�C�g��");
}
