#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Controller.h"
#include"Game.h"

CTitle::CTitle(CController* pController) :CScene(pController) {
	titleImage = LoadGraph("images/Title.bmp");
	startImage = LoadGraph("images/start_m.bmp");
	rankingImage = LoadGraph("images/ranking_m.bmp");;
	helpImage = LoadGraph("images/help_m.bmp");
	endImage = LoadGraph("images/end_m.bmp");
	menuCursor = 0;
	inputInterval = 0;
}

CScene* CTitle::Update() {
	keyInput = controller->control(false);

	SelectMenu();

	if (keyInput.Buttons[4] == true) {
		//ゲームシーンに移行
		return new CGame(controller);
	}
	
	return this;
}

void CTitle::SelectMenu() {
	if (keyInput.Buttons[XINPUT_BUTTON_DPAD_DOWN] == true) {
		if (++menuCursor > D_END)menuCursor = D_START;
	}
	if (keyInput.Buttons[XINPUT_BUTTON_DPAD_UP] == true) {
		if (--menuCursor < D_START)menuCursor = D_END;
	}
}

void CTitle::Render()const {
	DrawGraph(0, 0, titleImage, FALSE);
	DrawMenu();
}

void CTitle::DrawMenu()const {
	/*DrawGraph(D_POS_X, D_POS_Y + (D_HEIGHT * (int)EMenu::D_START) , startImage, TRUE);
	DrawGraph(D_POS_X, D_POS_Y + (D_HEIGHT * (int)EMenu::D_RANKING) , rankingImage, TRUE);
	DrawGraph(D_POS_X, D_POS_Y + (D_HEIGHT * (int)EMenu::D_HELP) , helpImage, TRUE);
	DrawGraph(D_POS_X, D_POS_Y + (D_HEIGHT * (int)EMenu::D_END) , endImage, TRUE);*/
	DrawFormatString(0, 0, 0XFFFFFF, "%d", menuCursor);
}