#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

/******************************************

*コンストラクタ

******************************************/
CAppleManager::CAppleManager()
{
	for (int i = 0; i < APPLE_MAX; i++) {
	    Apple[i] = new CApple();
	}
}

CAppleManager::~CAppleManager() { 
	for (int i = 0; i < APPLE_MAX; i++) {
		delete Apple[i];
	}
}

void CAppleManager::CreateApple()
{	
	for (int i = 0; i < APPLE_MAX; i++) {
			if (Apple[i]->getisShow() == FALSE) {
				delete Apple[i];
				Apple[i] = new CApple();
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
		if (!(++WaitTime % 25))CreateApple();
		Apple[i]->Update();
	}
}

void CAppleManager::Render() {
	for (int i = 0; i < APPLE_MAX; i++) {
	Apple[i]->Render();
    }
}