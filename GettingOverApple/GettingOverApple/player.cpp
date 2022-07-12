#include"DxLib.h"
#include"player.h"
#include"Controller.h"
#define D_KEY_CONTROL_LEFT -2000
#define D_KEY_CONTROL_RIGHT 2000

int i = 0;
//定数の宣言
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//自機の初期値
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
	speed = 3;
	g_player = LoadGraph("images/taiki.png");
}

void CPlayer::Update() {
	if (KeyControl() < 0)g_playerx -= speed; 
	if (0 < KeyControl())g_playerx += speed;

	//playerspeed();

	//画面をはみ出さないようにする
	if (g_playerx < 32)g_playerx = 32;
	if (g_playerx > SCREEN_WIDTH - 180)g_playerx = SCREEN_WIDTH - 180;
}
void CPlayer::Render()const {
	DrawRotaGraph((int)g_playerx, g_playery, 1.0f, 0, g_player, TRUE, FALSE);
	//DrawFormatString(0, 20, 0xFFFFFF, "%d", controller->control(true).ThumbLX);
}

void CPlayer::playerspeed() {
	if (KeyControl()<0) {// g_OldKey == 0 && g_NowKey == 0
		if (i < 25) {
			speed += i * 0.01f;
			i++;
		}
	}
	else if(0 < KeyControl()){
		if (i < 0) {
			speed -= i * 0.01f;
			i--;
		}
	}
}

int CPlayer::KeyControl() {
	short int key = (controller->GetControl()).ThumbLX;

	if ( D_KEY_CONTROL_RIGHT< key) {
		return 1;//右
	}
	else if(key < D_KEY_CONTROL_LEFT) {
		return -1;//左
	}
	else {
		return 0;
	}
	
}