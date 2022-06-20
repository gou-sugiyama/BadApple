#include "UI.h"
#include"DxLib.h"

UserInterface::UserInterface() {
	for (int i = 0; i < 4; i++) {
		m_AppleCount[i] = 0;
	}

	m_TimeLimit = 60 * 30;			//60�t���[��*30�b
}

void UserInterface::Draw() {
	--m_TimeLimit;
	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "��������" ,0x000000);					//���l�����ς�
	SetFontSize(50);
	DrawFormatString(545, 100, 0x000000, "%d", m_TimeLimit / 60);//���l�����ς�
	SetFontSize(16);
	//DrawFormatString(510, 180, 0x000000, "�擾���������S");
	/*DrawRotaGraph(523, 120, 0.3f, 0, g_Teki[0], TRUE, FALSE);
	DrawRotaGraph(573, 120, 0.3f, 0, g_Teki[1], TRUE, FALSE);
	DrawRotaGraph(623, 120, 0.3f, 0, g_Teki[2], TRUE, FALSE);*/

	DrawFormatString(510, 240, 0xFFFFFF, "%03d", m_AppleCount[0]);
	DrawFormatString(560, 240, 0xFFFFFF, "%03d", m_AppleCount[1]);
	DrawFormatString(610, 240, 0xFFFFFF, "%03d", m_AppleCount[2]);
	
	//�f�o�b�O���p���l
	//(510*50*n,0xFFFFFF,"%03d" ,)

	/*
	DrawFormatString(510, 200, 0x000000, "���s����");
	DrawFormatString(555, 220, 0xFFFFFF, "%08d", g_Mileage / 10);
	DrawFormatString(510, 240, 0x000000, "�X�s�[�h");
	DrawFormatString(555, 260, 0xFFFFFF, "%08d", g_player.speed);*/

	if (m_TimeLimit <= 0) {
		//TODO�@�������Ԃ�0�ɂȂ������ʑJ��
		//���̃Q�[���X�e�[�g��Ԃ�or�Q�[���X�e�[�g��ύX����
	}
}