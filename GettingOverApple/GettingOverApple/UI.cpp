#include "UI.h"
#include"DxLib.h"

CUI::CUI() {
	for (int i = 0; i < 4; i++) {
		AppleCount[i] = 0;
	}

	score = 0;
	TimeLimit = 60 * 10;			//60�t���[��*30�b
	isPause = false;
}

void CUI::Render() {
	int White = 0xFFFFFF;
	int Black = 0x000000;
	int const StrMargin = 20;
	if (isPause == false) {
		--TimeLimit;
	}
	else {
		SetFontSize(50);
		DrawString(0, 240, "------PAUSE------", White);
	}

	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "��������", Black);					//���l�����ς�
	SetFontSize(50);
	DrawFormatString(545, StrMargin * 5, Black, "%02d", TimeLimit / 60);//���l�����ς�
	SetFontSize(16);
	//DrawFormatString(510, 180, 0x000000, "�擾���������S");
	/*DrawRotaGraph(523, 120, 0.3f, 0, g_Teki[0], TRUE, FALSE);
	DrawRotaGraph(573, 120, 0.3f, 0, g_Teki[1], TRUE, FALSE);
	DrawRotaGraph(623, 120, 0.3f, 0, g_Teki[2], TRUE, FALSE);*/

	DrawFormatString(510, StrMargin * 12, White, "%03d", AppleCount[0]);
	DrawFormatString(560, StrMargin * 12, White, "%03d", AppleCount[1]);
	DrawFormatString(610, StrMargin * 12, White, "%03d", AppleCount[2]);

	DrawString(510, StrMargin * 14, "SCORE:", White);
	DrawFormatString(580, StrMargin * 14, White, "%06d", score);

	//�f�o�b�O�p���l (500,300+20*n)


	/*
	DrawFormatString(510, 200, 0x000000, "���s����");
	DrawFormatString(555, 220, 0xFFFFFF, "%08d", g_Mileage / 10);
	DrawFormatString(510, 240, 0x000000, "�X�s�[�h");
	DrawFormatString(555, 260, 0xFFFFFF, "%08d", g_player.speed);*/

	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_M) {		//�X�y�[�X�L�[�������ꂽ��PAUSE
		isPause = !isPause;
	}

	if (TimeLimit <= 0) {
		TimeLimit = 0;
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			TimeLimit = 60 * 30;		//TODO�f�o�b�O�p�F��ŏ���
		//TODO�@�������Ԃ�0�ɂȂ�����3�b��ɉ�ʑJ��
		//���̃Q�[���X�e�[�g��Ԃ�or�Q�[���X�e�[�g��ύX����
		}
	}
}