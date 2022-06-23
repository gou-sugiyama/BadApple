#include"DxLib.h"
#include "AppleManager.h"
#include"Apple.h"
#include"define.h"

CAppleManager::CAppleManager() {
	image= LoadGraph("images/Apple_2.png");
	
	Apple = new CApple(image);
	
}
CAppleManager::~CAppleManager() { delete Apple; }

bool CAppleManager::CreateApple() {
	if (Apple->getisShow() == false) {
		Apple = new CApple(image);
	}
	if (Apple->getY() >= D_SCREEN_HEIGHT + (D_APPLE_HEIGHT / 2)) {
		Apple->toggleisShow();
	}
	return true;
}

void CAppleManager::Update() {
	static int WaitTime = 0;
	if(!(++WaitTime%25))	CreateApple();
	Apple->Update();
}

void CAppleManager::Render() {
	Apple->Render();
}