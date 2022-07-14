#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"
#include"define.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
CApple::CApple() {
	//0�`�����ӏ��̐��Ɓ{�]������0.5 * �Q�[���̈�𓯂����ŕ�����
	x = (float)((GetRand(D_CREATE_POINT_NUM - 1) + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM));
	y = 0;
	width = 40;
	height = 40;
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
	x = (float)((GetRand(D_CREATE_POINT_NUM - 1) + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM));
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
	x = (float)((GetRand(D_CREATE_POINT_NUM - 1) + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM));
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
	x = (float)((GetRand(D_CREATE_POINT_NUM - 1) + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM));
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
	x = (float)((GetRand(D_CREATE_POINT_NUM - 1) + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM));
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

}

