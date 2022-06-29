#pragma once
#include"DxLib.h"
#include<stdio.h>
#include"Controller.h"
class CHitBoxCheck
{
private:
	int sx1;
	int sx2;
	int sy1;
	int sy2;

	int dx1;
	int dx2;
	int dy1;
	int dy2;

public:
	bool HitBox(CPlayer* pPlayer, CApple* pApple);
};

