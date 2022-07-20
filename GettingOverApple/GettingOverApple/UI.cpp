#include"DxLib.h"
#include "UI.h"
#include"Controller.h"
#include"Apple.h"
#include"define.h"

int White = 0xFFFFFF;
int Black = 0x000000;
int const StrMargin = 20;

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CUI::CUI(CController* pController) {
	controller = pController;
	for (int i = 0; i < D_COUNT_OBJECT; i++) {
		objectCount[i] = 0;
	}
	objectImage[D_APPLE_A] = LoadGraph("images/ringoA.png");
	objectImage[D_APPLE_B] = LoadGraph("images/ringoB.png");
	objectImage[D_APPLE_C] = LoadGraph("images/ringoC.png");

	score = 0;
	timeLimit = 60 * 30;			//60�t���[��*30�b
	isPause = false;
}

//--------------------------------
// �X�V
//--------------------------------
bool CUI::Update() {
	if (isPause == false) {
		--timeLimit;
	}

	if (timeLimit <= 0) {
		timeLimit = 0;

		return false;
		//TODO:�������Ԃ�0�ɂȂ�����3�b��ɉ�ʑJ��
		//���̃Q�[���X�e�[�g��Ԃ�or�Q�[���X�e�[�g��ύX����
	}

	//�X�^�[�g�{�^���������ꂽ��PAUSE
	if (controller->GetControl().Buttons[4]) {	
		isPause = !isPause;
	}
	return true;
}

//--------------------------------
// �`��
//--------------------------------
void CUI::Render()const {
	

	if (isPause) {
		SetFontSize(50);
		DrawString(35, 240, "------PAUSE------", White);
	}

	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "��������", Black);					//���l�����ς�
	SetFontSize(50);
	DrawFormatString(545, StrMargin * 5, Black, "%02d", timeLimit / 60);//���l�����ς�
	SetFontSize(16);

	DrawObjectCount();

	DrawString(510, StrMargin * 14, "SCORE:", White);
	DrawFormatString(580, StrMargin * 14, White, "%06d", score);

}

//--------------------------------
// �l�������I�u�W�F�N�g�̃J�E���g
//--------------------------------
void CUI::DrawObjectCount()const {
	const int DRAW_OBJECT = 510;
	for (int i = 0; i < D_COUNT_OBJECT; i++) {
		DrawGraph(D_GAME_AREA + 50 * i, 
			StrMargin * 10, objectImage[i], TRUE);

		DrawFormatString(DRAW_OBJECT + 50 * i, 
			StrMargin * 12, White, "%03d", objectCount[i]);
	}
}