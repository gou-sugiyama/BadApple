#include "UI.h"
#include"DxLib.h"

UserInterface::UserInterface() {
	for (int i = 0; i < 4; i++) {
		m_AppleCount[i] = 0;
	}
}

void UserInterface::Draw() {
	DrawBox(500, 0, 640, 480, 0x009900, TRUE);
	SetFontSize(16);
	DrawFormatString(510, 80, 0x000000, "取得したリンゴ");
	/*DrawRotaGraph(523, 120, 0.3f, 0, g_Teki[0], TRUE, FALSE);
	DrawRotaGraph(573, 120, 0.3f, 0, g_Teki[1], TRUE, FALSE);
	DrawRotaGraph(623, 120, 0.3f, 0, g_Teki[2], TRUE, FALSE);*/

	DrawFormatString(510, 140, 0xFFFFFF, "%03d", m_AppleCount[0]);
	DrawFormatString(560, 140, 0xFFFFFF, "%03d", m_AppleCount[1]);
	DrawFormatString(610, 140, 0xFFFFFF, "%03d", m_AppleCount[2]);
	DrawFormatString(510, 180, 0xFFFFFF, "%03d", m_AppleCount[3]);
	DrawFormatString(510, 200, 0x000000, "走行距離");
	DrawFormatString(555, 220, 0xFFFFFF, "%08d", g_Mileage / 10);
	DrawFormatString(510, 240, 0x000000, "スピード");
	DrawFormatString(555, 260, 0xFFFFFF, "%08d", g_player.speed);

}