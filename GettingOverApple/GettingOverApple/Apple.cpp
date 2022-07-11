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
	image = new int[IMAGE_MAX];
	image[D_APPLE_A] = LoadGraph("images/ringoA.png");
	image[D_APPLE_B] = LoadGraph("images/ringoB.png");
	image[D_APPLE_C] = LoadGraph("images/ringoC.png");
	image[D_APPLE_D] = LoadGraph("images/ringoD.png");
	imgHandle = 0;
	speed = 0;
	score = 0;
	isShow = false;
}

//-------------------------
// �f�X�g���N�^
//-------------------------
CApple::~CApple() {
	delete[] image;
}


//------------------------
// �X�V
//------------------------
void CApple::Update() {
	y += speed;
}

//------------------------
// �����S�̐���
//------------------------
void CApple::NewApple() {
	int selectApple = GetRand(9) + 1;
	if (selectApple <= D_PROPORTION_A) {
		CreateAppleA();
	}
	else if (selectApple <= D_PROPORTION_B) {
		CreateAppleB();
	}
	else if (selectApple <= D_PROPORTION_C) {
		CreateAppleC();
	}
	else if (selectApple <= D_PROPORTION_D) {
		CreateAppleD();
	}
}

//---------------------
// �����SA�̐���
//---------------------
void CApple::CreateAppleA() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	speed = D_APPLE_A_SPEED;
	score = D_APPLE_A_SCORE;
	imgHandle = D_APPLE_A;
	isShow = true;
}
//---------------------
// �����SB�̐���
//---------------------
void CApple::CreateAppleB() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	speed = D_APPLE_B_SPEED;
	score = D_APPLE_B_SCORE;
	imgHandle = D_APPLE_B;
	isShow = true;
}
//---------------------
// �����SC�̐���
//---------------------
void CApple::CreateAppleC() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	speed = D_APPLE_C_SPEED;
	score = D_APPLE_C_SCORE;
	imgHandle = D_APPLE_C;
	isShow = true;
}
//---------------------
// �����SD�̐���
//---------------------
void CApple::CreateAppleD() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	speed = D_APPLE_D_SPEED;
	score = D_APPLE_D_SCORE;
	imgHandle = D_APPLE_D;
	isShow = true;
}

//-------------------------
// �`��
//-------------------------
void CApple::Render()const {
	DrawGraph(x, y, image[imgHandle], TRUE);
}

