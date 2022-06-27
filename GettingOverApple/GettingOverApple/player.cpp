#include"DxLib.h"
#include"player.h"
#include"SceneManager.h"

int i = 0;
//íËêîÇÃêÈåæ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//é©ã@ÇÃèâä˙íl
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_WIDTH = 40;
const int PLAYER_HIGHT = 100;

CPlayer::CPlayer(CSceneManager* pManager) {
	manager = pManager;
	g_playerx = PLAYER_POS_X;
	g_playery = PLAYER_POS_Y;
	g_playerw = PLAYER_WIDTH;
	g_playerh = PLAYER_HIGHT;
	g_player = LoadGraph("images/car1pol.bmp");
}


void CPlayer::Render()const {
	DrawRotaGraph(g_playerx, g_playery, 1.0f,0, g_player, TRUE, FALSE);
}

void CPlayer::playerspeed() {
	if (*(manager->GetKey())) {// g_OldKey == 0 && g_NowKey == 0
		if (i < 25) {
			speed += i * 0.01;
			i++;
		}
	}
	else  {
		if (i < 0) {
			speed -= i * 0.01;
			i--;
		}
	}
}
void CPlayer::Update() {
	if (*(manager->GetKey()) & PAD_INPUT_LEFT)g_playerx -=speed ;
	if (*(manager->GetKey()) & PAD_INPUT_RIGHT)g_playerx += speed;

	playerspeed();

	//âÊñ ÇÇÕÇ›èoÇ≥Ç»Ç¢ÇÊÇ§Ç…Ç∑ÇÈ
	if (g_playerx < 32)g_playerx = 32;
	if (g_playerx > SCREEN_WIDTH - 180)g_playerx = SCREEN_WIDTH - 180;
}