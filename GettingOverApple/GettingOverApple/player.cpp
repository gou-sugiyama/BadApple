#include "DxLib.h"
#include"player.h"
#define _USE_MATH_DEFINES
#include <math.h>
int i = 0;
//íËêîÇÃêÈåæ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//é©ã@ÇÃèâä˙íl
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_WIDTH = 40;
const int PLAYER_HIGHT = 100;


void player::PlayerControl() {

}
int player::LoadImages() {
	if ((g_player = LoadGraph("images/taiki.png")) == -1)return -1;
}

void player::GameInit() {
	g_playerx = PLAYER_POS_X;
	g_playery = PLAYER_POS_Y;
	g_playerw = PLAYER_WIDTH;
	g_playerh = PLAYER_HIGHT;
}
void player::Draw() {
	DrawRotaGraph(g_playerx, g_playery, 1.0f,0, g_player, TRUE, FALSE);
}

void player::playerspeed(int g_Nowkey, int g_OldKey) {
	speed =0.0f;
	k = 0.01f;
	g = 0.01f;

	if (g_Nowkey) {// g_OldKey == 0 && g_NowKey == 0
		if ( k<25) {
			speed += k * 0.01;
			k++;
		}
	}	
	if (g_Nowkey) {
		if (k > 25) {
			speed += k * 0.01;
			k++;
		}
	}
}
void player::UpdateX(int g_Nowkey) {
	if (g_Nowkey & PAD_INPUT_LEFT)g_playerx -=speed ;
	if (g_Nowkey & PAD_INPUT_RIGHT)g_playerx += speed;
	DrawFormatString(0, 0, 0xFFFFFF, "%d", g_playerx);

	//âÊñ ÇÇÕÇ›èoÇ≥Ç»Ç¢ÇÊÇ§Ç…Ç∑ÇÈ
	if (g_playerx < 32)g_playerx = 32;
	if (g_playerx > SCREEN_WIDTH - 180)g_playerx = SCREEN_WIDTH - 180;
}