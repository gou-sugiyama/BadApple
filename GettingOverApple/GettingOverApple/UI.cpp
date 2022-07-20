#include"DxLib.h"
#include "UI.h"
#include"Controller.h"
#include"Apple.h"
#include"define.h"

int White = 0xFFFFFF;
int Black = 0x000000;
int const StrMargin = 20;

//--------------------------------
// コンストラクタ
//--------------------------------
CUI::CUI(CController* pController) {
	controller = pController;
	for (int i = 0; i < D_COUNT_OBJECT; i++) {
		objectCount[i] = 0;
	}
	objectImage[D_APPLE_A] = LoadGraph("images/ringoA.png");
	objectImage[D_APPLE_B] = LoadGraph("images/ringoB.png");
	objectImage[D_APPLE_C] = LoadGraph("images/ringoC.png");
	LoadDivGraph("images/number.png", 10, 10, 1, 30, 60, numberimage);


	score =00000;
	timeLimit = 60 * 30;			//60フレーム*30秒
	isPause = false;
}

//--------------------------------
// 更新
//--------------------------------
bool CUI::Update() {

	ChangeScoreImage();
	ChangeObjectImage();
	ChangeTimeImage();

	if (isPause == false) {
		--timeLimit;
	}

	if (timeLimit <= 0) {
		timeLimit = 0;

		return false;
		//TODO:制限時間が0になったら3秒後に画面遷移
		//次のゲームステートを返すorゲームステートを変更する
	}

	//スタートボタンが押されたらPAUSE
	if (controller->GetControl().Buttons[4]) {	
		isPause = !isPause;
	}
	return true;
}

//--------------------------------
// 描画
//--------------------------------
void CUI::Render()const {
	

	if (isPause) {
		SetFontSize(50);
		DrawString(35, 240, "------PAUSE------", Black);
	}

	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "制限時間", Black);					//数値調整済み
	SetFontSize(50);

	for (int i = 0; i < 2; i++) {
		DrawRotaGraph2(545 + i*60, StrMargin * 6
			, 30 / 2, 60 / 2, 1.6, 0, timeimage[i], TRUE);
	}

	//DrawFormatString(545, StrMargin * 5, Black, "%02d", timeLimit / 60);//数値調整済み
	SetFontSize(16);

	DrawObjectCount();

	DrawString(510, StrMargin * 15, "SCORE:", White);
	
	for (int i = 0; i < 5; i++) {
		DrawRotaGraph2(575 + i * 13, StrMargin*15
			, 30 / 2, 60 / 2, 0.5, 0, scoreimage[i], TRUE);
	}

}

//--------------------------------
// 獲得したオブジェクトのカウント
//--------------------------------
void CUI::DrawObjectCount()const {
	const int DRAW_OBJECT = 510;
	for (int i = 0; i < D_COUNT_OBJECT; i++) {
		DrawGraph(D_GAME_AREA + 50 * i, 
			StrMargin * 10, objectImage[i], TRUE);

		for (int j = 0; j < 3; j++) {
			DrawRotaGraph2(DRAW_OBJECT+j*12 + i *50, StrMargin * 12+15
				, 30 / 2, 60 / 2, 0.5, 0, objectcountimage[i][j], TRUE);
		}
		/*DrawFormatString(DRAW_OBJECT + 50 * i, 
			StrMargin * 12, White, "%03d", objectCount[i]);*/
	}
}

void CUI::ChangeScoreImage()
{
	int allnumber;
	int remembernumber[5];
	int x;
	allnumber = score;
	remembernumber[0] = allnumber / 10000;
	remembernumber[1] = (allnumber - remembernumber[0] * 10000) / 1000;
	remembernumber[2] = (allnumber - remembernumber[0] * 10000 - remembernumber[1] * 1000) / 100;
	remembernumber[3] = (allnumber - remembernumber[0] * 10000 - remembernumber[1] * 1000 - remembernumber[2] * 100) / 10;
	remembernumber[4] = (allnumber - remembernumber[0] * 10000 - remembernumber[1] * 1000 - remembernumber[2] * 100 - remembernumber[3] * 10);

	for (int i = 0; i < 5; i++) {
		x = remembernumber[i];
		scoreimage[i] = numberimage[x];
	}
}

void CUI::ChangeObjectImage()
{
	int allnumber;
	int remembernumber[3];
	int x;
	

	for(int i = 0; i < 3; i++) {
		allnumber = objectCount[i];
		remembernumber[0] = allnumber / 100;
		remembernumber[1] = (allnumber - remembernumber[0] * 100) / 10;
		remembernumber[2] = (allnumber - remembernumber[0] * 100 - remembernumber[1] * 10);

		for (int j = 0; j < 3; j++) {
			x = remembernumber[j];
			objectcountimage[i][j] = numberimage[x];
		}
	}
}

void CUI::ChangeTimeImage()
{
	int allnumber;
	int remembernumber[2];
	int x;
	allnumber = timeLimit/60;
	remembernumber[0] = allnumber / 10;
	remembernumber[1] = (allnumber - remembernumber[0] * 10);

	for (int i = 0; i < 2; i++) {
		x = remembernumber[i];
		timeimage[i] = numberimage[x];
	}

}
