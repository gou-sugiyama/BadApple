#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Ranking.h"
#include"Controller.h"
#include"Game.h"
#include"End.h"
#include"Help.h"

//-------------------------------
// �R���X�g���N�^
//-------------------------------
CTitle::CTitle(CController* pController) :CScene(pController) {
	titleImage = LoadGraph("images/Title.bmp");
	menuImage[D_START] = LoadGraph("images/start_m.bmp");
	menuImage[D_RANKING] = LoadGraph("images/ranking_m.bmp");;
	menuImage[D_HELP] = LoadGraph("images/help_m.bmp");
	menuImage[D_END] = LoadGraph("images/end_m.bmp");
	menuCursor = 0;
	keyInput = controller->control(true);
}

//-----------------------------
// �X�V
//-----------------------------
CScene* CTitle::Update() {
	keyInput = controller->control(false);

	SelectMenu();

	if (keyInput.Buttons[XINPUT_BUTTON_START] == TRUE) {
		switch (menuCursor) {
		case D_START:
			return new CGame(controller);		//�Q�[���V�[���Ɉڍs
			break;
		case D_RANKING:
			return new CRanking(controller);	//�����L���O�V�[���Ɉڍs
			break;
		case D_HELP:
			return new CHelp(controller);		//TODO:�w���v��ʂɈڍs
			break;
		case D_END:
			return new CEnd(controller);		//�G���h��ʂɈڍs
			break;
		default:
			return nullptr;
		}
	}

	return this;
}

//-----------------------------------
// ���j���[�I��
//-----------------------------------
void CTitle::SelectMenu() {
	if (keyInput.Buttons[XINPUT_BUTTON_DPAD_UP] == TRUE) {
		if (--menuCursor < D_START)menuCursor = D_END;
	}
	if (keyInput.Buttons[XINPUT_BUTTON_DPAD_DOWN] == TRUE) {
		if (++menuCursor > D_END)menuCursor = D_START;
	}
}

//--------------------------------
// �`��
//--------------------------------
void CTitle::Render()const {
	DrawGraph(0, 0, titleImage, FALSE);
	DrawMenu();
}

//-------------------------------
// ���j���[�̕`��
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

	DrawFormatString(0, 0, 0XFFFFFF, "%d", menuCursor);
}