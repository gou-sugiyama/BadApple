#include"DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include"player.h"
#include"Controller.h"
#define D_KEY_CONTROL_LEFT -2000
#define D_KEY_CONTROL_RIGHT 2000
//�萔�̐錾
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//���@�̏����l
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_WIDTH = 40;
const int PLAYER_HIGHT = 100;

CPlayer::CPlayer(CController* pController) {
	controller = pController;
	g_playerx = PLAYER_POS_X;
	g_playery = PLAYER_POS_Y;
	g_playerw = PLAYER_WIDTH;
	g_playerh = PLAYER_HIGHT;
	g_player = LoadGraph("images/taiki.png");
	g_playerRun = LoadGraph("images/run.png");
	g_playerflg = TRUE;
	g_playerflg = FALSE;
	mv = 0.05f;


	int i;
	for (i = 0; i < 180; i++) {//i�̕����ւǂꂭ�炢�i�ނ�
		fcos[i] = (float)cos(i * M_PI / 180);
	}

	cmx = 0.0;
	angle = -1;
	tnos = 0;//2�b
}

void CPlayer::Update() {
	//if (KeyControl() < 0)g_playerx -= cmx; 
	//if (0 < KeyControl())g_playerx += cmx;
	playerspeed();
	if (tnos > 0) {
		if (tnos-- % 20 == 0) {
			g_playerflg = !g_playerflg;
		}
	}
	else {
		tnos = 0;
		g_playerflg = true;
	}

	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
	if (g_playerx < 32) {
		g_playerx = 32;
		cmx = 0;
	}
	if (g_playerx > SCREEN_WIDTH - 180) {
		g_playerx = SCREEN_WIDTH - 180;
		cmx = 0;
	}


	//�L�����N�^�[�̍��W�𖈃t���[���ړ�������
	g_playerx += cmx;
}

void CPlayer::Render() {
	if (g_playerflg) {
		if (cmx > 0) {
			DrawRotaGraph((int)g_playerx, g_playery, 1.0f, 0, g_playerRun, TRUE, TRUE);//�E
		}
		if (cmx < 0) {
			DrawRotaGraph((int)g_playerx, g_playery, 1.0f, 0, g_playerRun, TRUE, FALSE);//��
		}
		if (cmx == 0) {
			DrawRotaGraph((int)g_playerx, g_playery, 1.0f, 0, g_player, TRUE, FALSE);//�ҋ@
		}
	}
	//DrawFormatString(0, 20, 0xFFFFFF, "%d", controller->control(true).ThumbLX);
}

void CPlayer::playerspeed() {

	//---------------------------------
	if (KeyControl() < 0) { //�E
		angle = 179;
	}
	else if (KeyControl() > 0) { //��
		angle = 0;
	}
	else {
		angle = -1;
	}
	//------------------------------------

	//---------------------------------------------
	//angle���ς������ړ��ʂ�ύX����
	if (angle != -1) {
		cmx += fcos[angle] * mv;
	}
	else if (angle == -1) {
		cmx -= fcos[angle] * mv;
	}
	if ((0.5 > cmx && KeyControl() != 1) && (cmx > -0.5 && KeyControl() != -1)) {
		cmx = 0;
	}
	//--------------------------------------------------
	
}

void CPlayer::HitAction() {//�_��
	tnos = 120;
}

int CPlayer::KeyControl() {
	short int key = (controller->GetControl()).ThumbLX;

	if ( D_KEY_CONTROL_RIGHT< key) {
		return 1;//�E
	}
	else if(key < D_KEY_CONTROL_LEFT) {
		return -1;//��
	}
	else {
		return 0;
	}
}
 
