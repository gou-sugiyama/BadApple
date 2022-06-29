#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

/******************************************

*コンストラクタ

******************************************/
CAppleManager::CAppleManager()
{
	image = LoadGraph("images/Apple_2.png");
	
	Apple = new CApple(image);

}CAppleManager::~CAppleManager() { delete Apple; }

bool CAppleManager::CreateApple()
{	
		if (Apple->getisShow() == FALSE) {
			delete Apple;
			Apple = new CApple(image);
			return TRUE;
		}
		return FALSE;
}

void CAppleManager::Update(){
	if (Apple->getY() >= D_SCREEN_HEIGHT) {
		Apple->toggleisShow();
	}
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) CreateApple();
	Apple->Update();
}

void CAppleManager::Render(){

	Apple->Render();
}