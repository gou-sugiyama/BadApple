#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

/******************************************

*コンストラクタ

******************************************/
CAppleManager::CAppleManager()
{
	image[0] = LoadGraph("images/Apple_2.png");
	image[1] = LoadGraph("images/BlueApple4.png");
	image[2] = LoadGraph("images/GoldApple.png");
	image[3] = LoadGraph("images/PoisonApple.png");
	for (int i = 0; i < APPLE_MAX; i++) {
		Apple[i] = new CApple(image);
	}
}CAppleManager::~CAppleManager() { delete Apple[4]; }

void CAppleManager::ControlApple() 
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (Apple[i]->getisShow() == TRUE) {
			//リンゴの表示
			Apple[i]->Render();
			if (Apple[i]->getisShow() == 4) {
				Apple[i]->toggleisShow();
			//	//画面をはみ出したら消去
			//	if (Apple[i]->getH() > D_SCREEN_HEIGHT)Apple[i]->getH() = FALSE;
			}
		}
	}
}


void CAppleManager::CreateApple()
{	
	for (int i = 0; i < APPLE_MAX; i++) {
			if (Apple[i]->getisShow() == FALSE) {
				delete Apple[i];
				Apple[i] = new CApple(image);
			}
			if (Apple[i]->getY() >= D_SCREEN_HEIGHT - APPLE_HEIGHT / 2) {
				Apple[i]->toggleisShow();
			}
	}
}

void CAppleManager::Update(){

	for (int i = 0; i < APPLE_MAX; i++) 
	{
		if (Apple[i]->getY() >= D_SCREEN_HEIGHT) 
		{
			Apple[i]->toggleisShow();
		}
		static int WaitTime = 0;
		if (!(++WaitTime % 25)) CreateApple();
		Apple[i]->Update();
	}
}

void CAppleManager::Render() {
	for (int i = 0; i < APPLE_MAX; i++) {
	Apple[i]->Render();
    }
}