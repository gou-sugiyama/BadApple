#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"

CAppleManager::CAppleManager()
{
	image = LoadGraph("images/Apple_2.png");
	Apple = new CApple(image);

}CAppleManager::~CAppleManager() { delete Apple; }

bool CAppleManager::CreateApple()
{
	
	for (int i = 0; i < APPLE_MAX; i++) {
		if (Apple->getisShow() == FALSE) {
			Apple = new CApple(image);
		}
		if (Apple->getY() >= SCREEN_HEIGHT - APPLE_HEIGHT / 2) {
			Apple->toggleisShow();
		}
		return TRUE;
	}
	return FALSE;
}

void CAppleManager::Update(){
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) CreateApple();
	Apple->Update();
}

void CAppleManager::Render(){

	Apple->Render();
}