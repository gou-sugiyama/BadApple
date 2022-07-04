#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Controller.h"
#include"Game.h"

enum class EMenu {
	E_START = 0
	,E_RANKING
	,E_HELP
	,E_END

};

CTitle::CTitle(CController* pController) :CScene(pController) {
	titleImage = LoadGraph("images/Title.bmp");
	startImage = LoadGraph("images/start_m.bmp");
	rankingImage = LoadGraph("images/ranking_m.bmp");;
	helpImage = LoadGraph("images/help_m.bmp");
	endImage = LoadGraph("images/end_m.bmp");
	menuCursor = 0;
}

CScene* CTitle::Update() {


	if ((controller->control(false)).Buttons[4] == true) {
		//ゲームシーンに移行
		return new CGame(controller);
	}
	return this;
}

void CTitle::Render()const {
	DrawGraph(0, 0, titleImage, FALSE);
}
