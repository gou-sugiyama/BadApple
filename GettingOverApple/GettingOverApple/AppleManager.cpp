#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

/******************************************

*コンストラクタ

******************************************/
CAppleManager::CAppleManager()
{
	image[0] = LoadGraph("images/Apple_2.png", 6);
	image[1] = LoadGraph("images/BlueApple4.png", 2);
	image[2] = LoadGraph("images/GoldApple.png", 1);
	image[3] = LoadGraph("images/PoisonApple.png", 1);

	isShow = TRUE;
}CAppleManager::~CAppleManager() { delete Apple; }

void CAppleManager::CreateApple()
{	
	for (int i = 0; i < APPLE_MAX; i++) {
			if (Apple[i]->getisShow() == FALSE) {
				delete Apple;
				Apple[i] = new CApple(image);
			}
			if (Apple[i]->getY() >= D_SCREEN_HEIGHT - APPLE_HEIGHT / 2) {
				Apple[i]->toggleisShow();
			}
	}
}

void CAppleManager::Update(){
	if (Apple[APPLE_MAX]->getY() >= D_SCREEN_HEIGHT) {
		Apple[APPLE_MAX]->toggleisShow();
	}
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) CreateApple();
	Apple[APPLE_MAX]->Update();
}

void CAppleManager::Render(){

	Apple[APPLE_MAX]->Render();
}