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
	count += 1;
	images[0] = LoadGraph("images/Apple_2.png");
	images[1] = LoadGraph("images/BlueApple4.png");
	images[2] = LoadGraph("images/GoldApple.png");
	images[3] = LoadGraph("images/PoisonApple.png");
	
	AppleCount1 = 0;
	AppleCount2 = 0;
	AppleCount3 = 0;
	
	DrawRotaGraph(523, 120, 0.3f, 0, images[0], TRUE, FALSE);
	DrawRotaGraph(573, 120, 0.3f, 0, images[1], TRUE, FALSE);
	DrawRotaGraph(623, 120, 0.3f, 0, images[2], TRUE, FALSE);
	
	DrawFormatString(510, 140, 0xFFFFFF, "%03d", AppleCount1);
	DrawFormatString(560, 140, 0xFFFFFF, "%03d", AppleCount2);
	DrawFormatString(610, 140, 0xFFFFFF, "%03d", AppleCount3);

	for (int i = 0; i < APPLE_MAX; i++) {
		col = GetRand(9);
		
		if (0 <= col && col <= 5) {
			type = 0;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images[0]);
		}
		else if (6 <= col && col <= 7) {
			type = 1;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images[1]);
		}
		else if (col == 8) {
			type = 2;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images[2]);
		}
		else {
			type = 3;
			Apple[i] = new CApple(type);
			Apple[i]->SetApple(images[3]);
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
					Apple[i]->SetApple(images[0]);
				}
				else if (6 <= col && col <= 7) {
					type = 1;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images[1]);
				}
				else if (col == 8) {
					type = 2;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images[2]);
				}
				else if (col == 9) {
					type = 3;
					Apple[i] = new CApple(type);
					Apple[i]->SetApple(images[3]);
				}
				else {
					if (count == 0) {
						if (type == 0)AppleCount1++;
						if (type == 1)AppleCount2++;
						if (type == 2)AppleCount3++;
					}
				}
			}
			/*if (Apple[i]->getY() >= D_GAME_AREA - APPLE_HEIGHT / 2) {
				Apple[i]->toggleisShow();
			}*/
			if (Apple[i]->getY() >= (APPLE_MAX - count) / 2) {
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
		return images[0];
	}
	else if (i == 1) {
		return images[1];
	}
	else if (i == 2) {
		return images[2];
	}
	else {
		return images[3];
	}
}


