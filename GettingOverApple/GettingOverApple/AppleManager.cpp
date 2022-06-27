#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"

AppleManager::AppleManager()
{
	image = LoadGraph("images/Apple_2.png");
	Apple = new APPLE(image);
   	//Apple->toggleisShow();
	//Apple = NULL;

}AppleManager::~AppleManager() { delete Apple; }

bool AppleManager::CreateApple()
{
	
	for (int i = 0; i < APPLE_MAX; i++) {
		if (Apple->getisShow() == FALSE) {
			Apple = new APPLE(image);
		}
		if (Apple->getY() >= SCREEN_HEIGHT - APPLE_HEIGHT / 2) {
			Apple->toggleisShow();
		}
		return TRUE;
	}
	return FALSE;
}

void AppleManager::Update(){
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) CreateApple();
	Apple->Update();
}

void AppleManager::Render(){

	Apple->Render();
}