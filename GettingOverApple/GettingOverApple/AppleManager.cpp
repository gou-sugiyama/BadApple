#include"Apple.h"
#include"AppleManager.h"
#include"define.h"

/******************************************

*コンストラクタ

******************************************/
CAppleManager::CAppleManager()
{
	WaitTime = 0;
	int col;
	int type;
	images1 = LoadGraph("images/Apple_2.png");
	images2 = LoadGraph("images/BlueApple4.png");
	images3 = LoadGraph("images/GoldApple.png");
	images4 = LoadGraph("images/PoisonApple.png");

	for (int i = 0; i < APPLE_MAX; i++) {
	    
		col = GetRand(9);
		if (0 <= col && col <= 5) {
			type = 0;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images1);
		}
		else if (6 <= col && col <= 7) {
			type = 1;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images2);
		}
		else if (col == 8) {
			type = 2;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images3);
		}
		else {
			type = 3;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images4);
		}
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

				int col = GetRand(9);
				int type;
				if (0 <= col && col <= 5) {
					type = 0;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images1);
				}
				else if (6 <= col && col <= 7) {
					type = 1;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images2);
				}
				else if (col == 8) {
					type = 2;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images3);
				}
				else {
					type = 3;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images4);
				}
			}
			if (Apple[i]->getY() >= D_SCREEN_HEIGHT - APPLE_HEIGHT / 2) {
				Apple[i]->toggleisShow();
			}
	}
}



void CAppleManager::Update(){

	for (int i = 0; i < APPLE_MAX; i++)
	{
		if (Apple[i]->GetAppleFlg() == TRUE) {
			Apple[i]->Update();

			if (Apple[i]->getY() >= 480)
			{
				Apple[i]->toggleisShow();
			}
		}

		if (!(++WaitTime % 25)){
			CreateApple();
			WaitTime = 0;
		}
	
	}
}

void CAppleManager::Render() const{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (Apple[i]->GetAppleFlg() == TRUE) {
			Apple[i]->Render();
		}
    }
}

int CAppleManager::GetImage(int i)
{
	if (i == 0) {
		return images1;
	}
	else if (i == 1) {
		return images2;
	}
	else if (i == 2) {
		return images3;
	}
	else {
		return images4;
	}
}




