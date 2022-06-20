#include "UI.h"
#include"DxLib.h"

UserInterface::UserInterface() {
	for (int i = 0; i < 4; i++) {
		m_AppleCount[i] = 0;
	}

	m_score = 0;
	m_TimeLimit = 60 * 10;			//60フレーム*30秒
	isPause = false;
}

void UserInterface::Draw() {
	int White = 0xFFFFFF;
	int Black = 0x000000;
	int const DStrMargin = 20;
	if (isPause == false) {
		--m_TimeLimit;
	}
	else {
		SetFontSize(50);
		DrawString(0, 240, "------PAUSE------", White);
	}

	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(30);
	DrawString(508, 30, "制限時間", Black);					//数値調整済み
	SetFontSize(50);
	DrawFormatString(545, DStrMargin * 5, Black, "%02d", m_TimeLimit / 60);//数値調整済み
	SetFontSize(16);
	//DrawFormatString(510, 180, 0x000000, "取得したリンゴ");
	/*DrawRotaGraph(523, 120, 0.3f, 0, g_Teki[0], TRUE, FALSE);
	DrawRotaGraph(573, 120, 0.3f, 0, g_Teki[1], TRUE, FALSE);
	DrawRotaGraph(623, 120, 0.3f, 0, g_Teki[2], TRUE, FALSE);*/

	DrawFormatString(510, DStrMargin * 12, White, "%03d", m_AppleCount[0]);
	DrawFormatString(560, DStrMargin * 12, White, "%03d", m_AppleCount[1]);
	DrawFormatString(610, DStrMargin * 12, White, "%03d", m_AppleCount[2]);

	DrawString(510, DStrMargin * 14, "SCORE:", White);
	DrawFormatString(580, DStrMargin * 14, White, "%06d", m_score);

	//デバッグ用数値 (500,300+20*n)


	/*
	DrawFormatString(510, 200, 0x000000, "走行距離");
	DrawFormatString(555, 220, 0xFFFFFF, "%08d", g_Mileage / 10);
	DrawFormatString(510, 240, 0x000000, "スピード");
	DrawFormatString(555, 260, 0xFFFFFF, "%08d", g_player.speed);*/

	if (GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_M) {		//スペースキーが押されたらPAUSE
		isPause = !isPause;
	}

	if (m_TimeLimit <= 0) {
		m_TimeLimit = 0;
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			m_TimeLimit = 60 * 30;		//TODOデバッグ用：後で消す
		//TODO　制限時間が0になったら3秒後に画面遷移
		//次のゲームステートを返すorゲームステートを変更する
		}
	}
}