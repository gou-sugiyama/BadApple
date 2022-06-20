#include "DxLib.h"
#include"player.h"
#define _USE_MATH_DEFINES
#include <math.h>
int speed = 0;
//定数の宣言
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//自機の初期値
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_WIDTH = 40;
const int PLAYER_HIGHT = 100;
const int PLAYER_SPEED = 5;
void player::PlayerControl() {
    //左右移動
	if (g_playerflg == TRUE) {
		if (g_Nowkey & PAD_INPUT_LEFT)g_playerx -= 5;
		if (g_Nowkey & PAD_INPUT_RIGHT)g_playerx += 5;
	}
	//画面をはみ出さないようにする
	if (g_playerx < 32)g_playerx = 32;
	if (g_playerx > SCREEN_WIDTH - 180)g_playerx = SCREEN_WIDTH - 180;
	if (g_playery < 60)g_playery = 60;
	if (g_playery > SCREEN_HEIGHT - 60)g_playery = SCREEN_HEIGHT - 60;
	//プレイヤーの表示

	DrawRotaGraph(g_playerx, g_playery, 1.0f, 18, g_player, TRUE, FALSE);

	if (g_playerflg == TRUE) {
		if (g_Nowkey & PAD_INPUT_LEFT) {
			DrawRotaGraph(g_playerx, g_playery, 1.0f,18, g_player, TRUE, FALSE);
		}
		else if (g_Nowkey & PAD_INPUT_RIGHT) {
			DrawRotaGraph(g_playerx, g_playery, 1.0f,18, g_player, TRUE, FALSE);
		}
		else {
			DrawRotaGraph(g_playerx, g_playery, 1.0f, 0, g_player, TRUE, FALSE);
		}
	}
}
int player::LoadImages() {
	if ((g_player = LoadGraph("images/car1pol.bmp")) == -1)return -1;
}
void player::GameInit() {
	g_playerx = PLAYER_POS_X;
	g_playery = PLAYER_POS_Y;
	g_playerw = PLAYER_WIDTH;
	g_playerh = PLAYER_HIGHT;
}
void player::Draw() {
	DrawRotaGraph(g_playerx, g_playery, 1.0f,M_PI/18, g_player, TRUE, FALSE);
}
void player::playerspeed() {
	if (g_OldKey == g_Nowkey) {
		if (speed <= 5) {
			speed += i * 0.5;
			i++;
		}
	}
	else if (g_OldKey) {
		if (speed >= -5) {
			speed += -i * 0.5;
			i--;
		}
	}
}
