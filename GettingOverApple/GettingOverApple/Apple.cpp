#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"
#include"define.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
CApple::CApple() {
	//0�`�����ӏ��̐��Ɓ{�]������0.5 * �Q�[���̈�𓯂����ŕ�����
	x = 0;
	y = 0;
	width = D_APPLE_WIDTH;
	height = D_APPLE_HEIGHT;
	rangeX = (float)(width / 2);
	rangeY = (float)(height / 2);
	image = new int[D_APPLE_IMAGE_MAX];
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
void CApple::NewApple(float x) {
	int selectApple = GetRand(9) + 1;
	if (selectApple <= D_PROPORTION_A) {
		CreateAppleA(x);
	}
	else if (selectApple <= D_PROPORTION_B) {
		CreateAppleB(x);
	}
	else if (selectApple <= D_PROPORTION_C) {
		CreateAppleC(x);
	}
	else if (selectApple <= D_PROPORTION_D) {
		CreateAppleD(x);
	}
}

//---------------------
// �����SA�̐���
//---------------------
void CApple::CreateAppleA(float x) {
	this->x = x;
	y = 0;
	speed = D_APPLE_A_SPEED;
	score = D_APPLE_A_SCORE;
	imgHandle = D_APPLE_A;
	isShow = true;
}
//---------------------
// �����SB�̐���
//---------------------
void CApple::CreateAppleB(float x) {
	this->x = x;
	y = 0;
	speed = D_APPLE_B_SPEED;
	score = D_APPLE_B_SCORE;
	imgHandle = D_APPLE_B;
	isShow = true;
}
//---------------------
// �����SC�̐���
//---------------------
void CApple::CreateAppleC(float x) {
	this->x = x;
	y = 0;
	speed = D_APPLE_C_SPEED;
	score = D_APPLE_C_SCORE;
	imgHandle = D_APPLE_C;
	isShow = true;
}
//---------------------
// �����SD�̐���
//---------------------
void CApple::CreateAppleD(float x) {
	this->x = x;
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
	DrawRotaGraphF(x, y, 1.0f, 0, image[imgHandle], TRUE);
}

//-------------------------
// ����������
//-------------------------
void CApple::HitAction() {
	isShow = false;
	y = 0;
}

