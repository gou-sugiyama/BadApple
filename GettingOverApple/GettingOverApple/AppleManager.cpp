#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"

AppleManager::AppleManager()
{
	image[0] = LoadGraph("images/Apple_2.png");
	image[1] = LoadGraph("images/BlueApple_2.png");
	image[2] = LoadGraph("images/GoldApple_2.png");
	image[3] = LoadGraph("images/PoisonApple_2.png");
	Apple = new APPLE(image[4]);
	//リンゴ初期処理
	for (int i = 0; i < 4; i++) {
		isShow = FALSE;
	}
	////走行距離ごとに摘出現パターンを制御する
	//if (image[i] / 10 % 50 == 0) {
	//	CreateApple();
	//}
	CreateApple();
}AppleManager::~AppleManager() { delete Apple; }

bool AppleManager::CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
			//DrawRotaGraph(GetRand(6) * 71 + 35, 40, 1.0f, 0, image, TRUE, FALSE);
			//if (isShow == FALSE)continue;
			if (Apple->getisShow() == FALSE) {
				Apple = new APPLE(image[i]);
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