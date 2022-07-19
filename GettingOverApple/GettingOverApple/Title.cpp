#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"RankMng.h"
#include"Controller.h"
#include"Game.h"
#include"End.h"
#include"Help.h"

//-------------------------------
// �R���X�g���N�^
//-------------------------------
CTitle::CTitle(CController* pController) :CScene(pController) {
	titleImage = LoadGraph("images/title.png");
	menuImage[D_START] = LoadGraph("images/start_m.png");
	menuImage[D_RANKING] = LoadGraph("images/ranking_m.png");
	menuImage[D_HELP] = LoadGraph("images/help_m.png");
	menuImage[D_END] = LoadGraph("images/end_m.png");
	//�^�C�g��BGM
	TitleBGM = LoadSoundMem("sounds/BGM/������ 8bit29 (online-audio-converter.com) (1).wav");
	menuCursor = 0;
	keyInput = controller->control(true);
}

//-----------------------------
// �X�V
//-----------------------------
CScene* CTitle::Update() {
	keyInput = controller->control(true);

	SelectMenu();

	//�^�C�g��BGM���X�^�[�g
	if (CheckSoundMem(TitleBGM) == 0) {
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK,TRUE);
	}

	if (keyInput.Buttons[XINPUT_BUTTON_A] == TRUE) {
		switch (menuCursor) {
		case D_START:
			StopSoundMem(TitleBGM);
			return new CGame(controller);		//�Q�[���V�[���Ɉڍs
			break;
		case D_RANKING:
			StopSoundMem(TitleBGM);
			return new CRankMng(controller);	//�����L���O�V�[���Ɉڍs
			break;
		case D_HELP:
			StopSoundMem(TitleBGM);
			return new CHelp(controller);		//TODO:�w���v��ʂɈڍs
			break;
		case D_END:
			StopSoundMem(TitleBGM);
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
	//�^�C�g��BGM���X�^�[�g
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
}