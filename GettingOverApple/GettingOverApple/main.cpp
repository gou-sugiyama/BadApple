#include "DxLib.h"
#define RANKING_DATA 5
#include"UI.h"

UserInterface UI;

/*************************************************************************
*	�萔�̐錾
**************************************************************************/
//��ʗ̈�̑傫��
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*************************************************************************
*	�ϐ��̐錾
**************************************************************************/

int g_OldKey;	//�O��̓��̓L�[
int g_NowKey;	//����̓��̓L�[
int g_KeyFlg;	//���̓L�[���

int g_GameState = 0;	//�Q�[�����[�h
int g_Score = 0; //�X�R�A

int g_WaitTime = 0;

int g_TitleImage;	//�摜�p�ϐ�
int g_EndImage;
int g_Menu;
int g_RankingImage;  //�����L���O�摜�p�ϐ�

int g_StageImage;

//�����L���O�f�[�^�i�\���́j
struct RankingData {
	int no;
	char name[11];
	long score;
};

//	�����L���O�f�[�^�̕ϐ��錾
struct RankingData g_Ranking[RANKING_DATA];


/*************************************************************************
*	�֐��̃v���g�^�C�v�錾
**************************************************************************/

void DrawGameTitle(void);		//�^�C�g���`�揈��
void DrawHelp(void);			//�Q�[���w���v�`�揈��
void GameInit(void);		//�Q�[����������
void GameMain(void);		//�Q�[�����C������
void DrawGameOver(void);		//�Q�[���I�[�o�[��ʏ���
void DrawEnd(void);			//�Q�[���G���h�`�揈��

void DrawRanking(void);			//�����L���O�`�揈��
void InputRanking(void);		//�����L���O����
void SortRanking(void);				//�����L���O���בւ�
int SaveRanking(void);			//�����L���O�f�[�^�̕ۑ�
int ReadRanking(void);				//�����L���O�f�[�^�ǂݍ���

int LoadImages();		//�摜�Ǎ���


/*************************************************************************
*	�v���O�����̊J�n
**************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpcmdLine, int nCmdShow) {
	SetMainWindowText("GettingOverApple");

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	if (LoadImages() == -1)return -1;

	//�����L���O�f�[�^�ǂݍ���
	if (ReadRanking() == -1) return -1;

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)) {
		//���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		//��ʂ̏�����

		GameMain();				//�Q�[�����C������

		ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f
	}
	DxLib_End();					//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�I��
}

/*************************************************************************
*	�Q�[���^�C�g���\���i���j���[��ʁj
**************************************************************************/
void DrawGameTitle(void) {
	static int MenuNo = 0;

	//���j���[�J�[�\���ړ�����
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNo > 3)MenuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--MenuNo < 0)MenuNo = 3;
	}
	//Z�L�[�Ń��j���[�I��
	if (g_KeyFlg & PAD_INPUT_A)g_GameState = MenuNo + 1;

	//�^�C�g���摜�\��
	DrawGraph(0, 0, g_TitleImage, FALSE);

	//���j���[
	DrawGraph(120, 200, g_Menu, TRUE);

	//���j���[�J�[�\��
	//DrawRotaGraph(90, 220 + MenuNo * 40, 0.7f, M_PI / 2, g_Cone, TRUE);

}

/*************************************************************************
*�@�Q�[���w���v�`�揈��
**************************************************************************/
void DrawHelp(void) {
	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;
}

/*************************************************************************
*	�Q�[����������
**************************************************************************/
void GameInit(void) {
	//�X�R�A�̏�����
	g_Score = 0;

	//�Q�[�����C��������
	g_GameState = 5;
}

/*************************************************************************
*�@�Q�[�����C��
**************************************************************************/
void GameMain(void) {
	UI.Draw();
}

/*************************************************************************
*�@�Q�[���G���h�`�揈��
**************************************************************************/
void DrawEnd(void) {
	//�G���h�摜�\��
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(360, 480 - 24, "Thank you for playing", 0xffffff, 0);

	//�^�C���̉��Z�������I��(3�b��)
	if (++g_WaitTime > 180)g_GameState = 99;

}


/*************************************************************************
*�@�Q�[���I�[�o�[��ʏ���
**************************************************************************/
void DrawGameOver(void) {
	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M) {
		if (g_Ranking[RANKING_DATA - 1].score >= g_Score) {
			g_GameState = 0;
		}
		else {
			g_GameState = 7;
		}
	}
	DrawBox(150, 150, 490, 330, 0x009900, TRUE);
	DrawBox(150, 150, 490, 330, 0x000000, FALSE);

	SetFontSize(20);
	DrawString(310, 310, "�X�R�A�@", 0x000000);
	DrawFormatString(260, 310, 0xFFFFFF, "             =%6d", g_Score);

	DrawString(150, 450, "---- �X�y�[�X�L�[�������ă^�C�g���֖߂� ----", 0xffffff, 0);

}

/*************************************************************************
*�@�Q�[�������L���O�`��\��
**************************************************************************/
void DrawRanking(void) {
	//�X�y�[�X�L�[�Ń��j���[�ɖ߂�
	if (g_KeyFlg & PAD_INPUT_M)g_GameState = 0;

	//�����L���O�摜�\��
	DrawGraph(0, 0, g_RankingImage, FALSE);

	//�����L���O�ꗗ��\��
	SetFontSize(18);
	for (int i = 0; i < RANKING_DATA; i++) {
		DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-10s %10d",
			g_Ranking[i].no,
			g_Ranking[i].name,
			g_Ranking[i].score);
	}

	DrawString(100, 450, "----�X�y�[�X�L�[�������ă^�C�g���֖߂�----", 0xffffff, 0);
}

/*************************************************************************
*�@�����L���O���͏���
**************************************************************************/
void InputRanking(void) {
	//�����L���O�摜�\��
	DrawGraph(0, 0, g_RankingImage, FALSE);

	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(20);

	// ���O���͎w��������̕`��
	DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
	DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xFFFFFF);

	// ���O�̓���
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[RANKING_DATA - 1].name, FALSE) == 1) {
		g_Ranking[RANKING_DATA - 1].score = g_Score;	// �����L���O�f�[�^��5�ԖڂɃX�R�A��o�^
		SortRanking();		// �����L���O���בւ�
		SaveRanking();		// �����L���O�f�[�^�̕ۑ�
		g_GameState = 2;		// �Q�[�����[�h�̕ύX
	}
}

/***********************************************
 * �����L���O���בւ�
 ***********************************************/
void SortRanking(void)
{
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				work = g_Ranking[i];
				g_Ranking[i] = g_Ranking[j];
				g_Ranking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < RANKING_DATA; i++) {
		g_Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANKING_DATA - 1; i++) {
		for (j = i + 1; j < RANKING_DATA; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}

/***********************************************
 * �����L���O�f�[�^�̕ۑ�
 ***********************************************/
int  SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)
	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANKING_DATA; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}

/*************************************
 * �����L���O�f�[�^�ǂݍ���
 *************************************/
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^���z��f�[�^��ǂݍ���
	for (int i = 0; i < RANKING_DATA; i++) {
		int Q = fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}

/*************************************************************************
*�@�摜����
**************************************************************************/
int LoadImages() {
	//�^�C�g��
	if ((g_TitleImage = LoadGraph("images/Title.bmp")) == -1) return -1;				//�������ւ�
	//���j���[
	if ((g_Menu = LoadGraph("images/menu.bmp")) == -1)return-1;							//�������ւ�

	//�����L���O�f�[�^
	if ((g_RankingImage = LoadGraph("images/Ranking.bmp")) == -1)return -1;				//�������ւ�

	//�G���f�B���O
	if ((g_EndImage = LoadGraph("images/End.bmp")) == -1)return -1;						//�������ւ�

	//�v���C���[
	
	
	//�X�e�[�W�w�i
	if ((g_StageImage = LoadGraph("images/back.bmp")) == -1)return -1;					//�������ւ�

	return 0;
}

