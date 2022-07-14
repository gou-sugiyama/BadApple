#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

/******************************************

*コンストラクタ

******************************************/
CAppleManager::CAppleManager()
{
	WaitTime = 0;

	for (int i = 0; i < 4; i++) {
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
			if (Apple[i]->GetAppleFlg() == FALSE) {
				delete Apple[i];
				Apple[i] = new CApple();
			}
			/*if (Apple[i]->getY() >= D_SCREEN_HEIGHT - APPLE_HEIGHT / 2) {
				Apple[i]->toggleisShow();
			}*/
	}
}



void CAppleManager::Update(){

	for (int i = 0; i < APPLE_MAX; i++)
	{
		Apple[i]->Update();

		if (Apple[i]->getY() >= D_SCREEN_HEIGHT)
		{
			Apple[i]->toggleisShow();
		}
	
		if (!(++WaitTime % 25)){
			CreateApple();
			WaitTime = 0;
		}
	
	}
}

void CAppleManager::Render() const {
	for (int i = 0; i < APPLE_MAX; i++) {
			Apple[i]->Render();
    }
}

int CAppleManager::GetImage(int i)
{
	return image[i];
}
