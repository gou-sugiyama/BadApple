#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
CApple::CApple() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	image = LoadGraph("images/Apple_2.png");
	speed = 3;
	score = 0;
	isShow = false;
}

//------------------------
// �X�V
//------------------------
void CApple::Update() {
	y += speed;
}

//------------------------
// �����S�̐����F������
//------------------------
void CApple::AppleInit(int type) {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	image = LoadGraph("images/Apple_2.png");
	speed = GetRand(9) + 1;
	score = 0;
	isShow = true;
}

//-------------------------
// �`��
//-------------------------
void CApple::Render()const {
	DrawGraph(x, y, image, TRUE);
}

