#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {
	image = LoadGraph("images/haikei.png");
}

//--------------------------------
// �X�V
//--------------------------------
CScene* CEnd::Update() {
	static int limit = 180;
	if (limit-- < 0) {
		return nullptr;
	}
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CEnd::Render()const {
	DrawGraph(0, 0, image, FALSE);

	SetFontSize(24);
	DrawString(100, 170 + scrolY, "�^�C�g���@�@�@�����S���Ƃ�", 0xf50f05);
	DrawString(100, 200 + scrolY, "�o�[�W�����@�@1.0", 0x000000);
	DrawString(100, 230 + scrolY, "�ŏI�X�V���@�@2022�N07��20��", 0x000000);
	DrawString(100, 260 + scrolY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0x000000);
	DrawString(100, 290 + scrolY, "�@�@�@�@�@�@�@		�`�[��2-3d", 0x000000);
	DrawString(100, 310 + scrolY, "�f�ޗ��p", 0x000000);
	DrawString(100, 340 + scrolY, "�@BGM�@�@�@ �@������", 0x000000);
	DrawString(100, 365 + scrolY, "�@SE�@�@�@�@�@������", 0x000000);
}