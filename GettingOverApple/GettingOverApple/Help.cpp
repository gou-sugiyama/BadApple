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
	HelpBGM = LoadSoundMem("sounds/BGM/魔王魂 サイバー41 (online-audio-converter.com).wav");
}

//--------------------------------
// 更新
//--------------------------------
CScene* CHelp::Update() {
	if (CheckSoundMem(HelpBGM) == 0) {
		PlaySoundMem(HelpBGM, DX_PLAYTYPE_BACK, TRUE);
	}

	if (controller->GetControl().Buttons[XINPUT_BUTTON_B]) {
		StopSoundMem(HelpBGM);
		return new CTitle(controller);
	}
	if (controller->GetControl().Buttons[XINPUT_BUTTON_A]) {
		StopSoundMem(HelpBGM);
		return new CGame(controller);
	}
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CHelp::Render()const {
	DrawGraph(0, 0, image, FALSE);
}