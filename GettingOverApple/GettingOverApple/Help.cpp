#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "Help.h"
#include"Game.h"
#include"Title.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CHelp::CHelp(CController* pController) :CScene(pController) {
	image = LoadGraph("images/help.png");
}

//--------------------------------
// �X�V
//--------------------------------
CScene* CHelp::Update() {
	if (controller->GetControl().Buttons[XINPUT_BUTTON_B])
		return new CTitle(controller);


	if (controller->GetControl().Buttons[XINPUT_BUTTON_A])
		return new CGame(controller);

	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CHelp::Render()const {
	DrawGraph(0, 0, image, FALSE);
}