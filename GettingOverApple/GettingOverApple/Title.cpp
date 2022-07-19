#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"RankMng.h"
#include"Controller.h"
#include"Game.h"
#include"End.h"
#include"Help.h"

//-------------------------------
// コンストラクタ
//-------------------------------
CTitle::CTitle(CController* pController) :CScene(pController) {
	titleImage = LoadGraph("images/title.png");
	menuImage[D_START] = LoadGraph("images/start_m.png");
	menuImage[D_RANKING] = LoadGraph("images/ranking_m.png");
	menuImage[D_HELP] = LoadGraph("images/help_m.png");
	menuImage[D_END] = LoadGraph("images/end_m.png");
	//タイトルBGM
	TitleBGM = LoadSoundMem("sounds/BGM/魔王魂 8bit29 (online-audio-converter.com) (1).wav");
	menuCursor = 0;
	keyInput = controller->control(true);
}

//-----------------------------
// 更新
//-----------------------------
CScene* CTitle::Update() {
	keyInput = controller->control(true);

	SelectMenu();

	//タイトルBGMをスタート
	if (CheckSoundMem(TitleBGM) == 0) {
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK,TRUE);
	}

	if (keyInput.Buttons[XINPUT_BUTTON_A] == TRUE) {
		switch (menuCursor) {
		case D_START:
			StopSoundMem(TitleBGM);
			return new CGame(controller);		//ゲームシーンに移行
			break;
		case D_RANKING:
			StopSoundMem(TitleBGM);
			return new CRankMng(controller);	//ランキングシーンに移行
			break;
		case D_HELP:
			StopSoundMem(TitleBGM);
			return new CHelp(controller);		//TODO:ヘルプ画面に移行
			break;
		case D_END:
			StopSoundMem(TitleBGM);
			return new CEnd(controller);		//エンド画面に移行
			break;
		default:
			return nullptr;
		}
	}

	return this;
}

//-----------------------------------
// メニュー選択
//-----------------------------------
void CTitle::SelectMenu() {
	//タイトルBGMをスタート
	if (CheckSoundMem(TitleBGM) == 0) {
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK,FALSE);
	}
	if (keyInput.Buttons[XINPUT_BUTTON_DPAD_UP] == TRUE) {
		if (--menuCursor < D_START)menuCursor = D_END;
	}
	if (keyInput.Buttons[XINPUT_BUTTON_DPAD_DOWN] == TRUE) {
		if (++menuCursor > D_END)menuCursor = D_START;
	}
}

//--------------------------------
// 描画
//--------------------------------
void CTitle::Render()const {
	DrawGraph(0, 0, titleImage, FALSE);
	DrawMenu();
}

//-------------------------------
// メニューの描画
//-------------------------------
void CTitle::DrawMenu()const {
	for (int i = 0; i <= D_END; i++) {
		if (i == menuCursor) {
			DrawRotaGraph2(D_POS_X, D_POS_Y + D_HEIGHT * i
				, D_WIDTH / 2, D_HEIGHT / 2, D_ENLARGEMENT, 0, menuImage[i], TRUE);
		}
		else {
			DrawRotaGraph2(D_POS_X, D_POS_Y + D_HEIGHT * i
				, D_WIDTH / 2, D_HEIGHT / 2, 1.0, 0, menuImage[i], TRUE);
		}
	}
}