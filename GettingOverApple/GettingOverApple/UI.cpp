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

	score = 0;
	timeLimit = 60 * 30;			//60フレーム*30秒
	isPause = false;
}

//--------------------------------
// 更新
//--------------------------------
bool CUI::Update() {
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
		DrawString(35, 240, "------PAUSE------", White);
	}

	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "制限時間", Black);					//数値調整済み
	SetFontSize(50);
	DrawFormatString(545, StrMargin * 5, Black, "%02d", timeLimit / 60);//数値調整済み
	SetFontSize(16);

	DrawObjectCount();

	DrawString(510, StrMargin * 14, "SCORE:", White);
	DrawFormatString(580, StrMargin * 14, White, "%06d", score);

}

//--------------------------------
// 獲得したオブジェクトのカウント
//--------------------------------
void CUI::DrawObjectCount()const {
	const int DRAW_OBJECT = 510;
	for (int i = 0; i < D_COUNT_OBJECT; i++) {
		DrawGraph(D_GAME_AREA + 50 * i, 
			StrMargin * 10, objectImage[i], TRUE);

		DrawFormatString(DRAW_OBJECT + 50 * i, 
			StrMargin * 12, White, "%03d", objectCount[i]);
	}
}