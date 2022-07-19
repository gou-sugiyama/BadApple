#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "Help.h"
#include"Game.h"
#include"Title.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CHelp::CHelp(CController* pController) :CScene(pController) {
	image = LoadGraph("images/help.png");
}

//--------------------------------
// 更新
//--------------------------------
CScene* CHelp::Update() {
	if (controller->GetControl().Buttons[XINPUT_BUTTON_B])
		return new CTitle(controller);


	if (controller->GetControl().Buttons[XINPUT_BUTTON_A])
		return new CGame(controller);

	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CHelp::Render()const {
	DrawGraph(0, 0, image, FALSE);
}