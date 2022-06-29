#include "Hit.h"

bool CHitBoxCheck::HitBox(CPlayer* pPlayer, CApple* pApple)
{

	//xy,は中心座標とする
	int sx1 = pPlayer->GetPlayerX() - pPlayer->GetPlayerW() / 2;
	int sy1 = pPlayer->GetPlayerY() - pPlayer->GetPlayerH() / 2;
	int sx2 = sx1 + pPlayer->GetPlayerW();
	int sy2 = sy1 + pPlayer->GetPlayerH();

	int dx1 = pApple->getX();
	int dy1 = pApple->getY();
	int dx2 = dx1 + pApple->getW();
	int dy2 = dy1 + pApple->getH();

	//短形が重なっていれば当たり
	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		if (sx1 < dx2)DrawFormatString(0, 20 * 3, 0xFFFFFF, "dx1:%d", dx1);
		if (dx1 < sx2)DrawFormatString(0, 20 * 4, 0xFFFFFF, "dx2:%d", dx2);
		if (sy1 < dy2)DrawFormatString(0, 20 * 5, 0xFFFFFF, "dy1:%d", dy1);
		if (dy1 < sy2)DrawFormatString(0, 20 * 6, 0xFFFFFF, "dy2:%d", dy2);
		return TRUE;
	}
	else {
		return FALSE;
	}
}
