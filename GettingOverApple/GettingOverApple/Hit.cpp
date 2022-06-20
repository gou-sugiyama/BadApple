#include"DxLib.h"
#include<stdio.h>

#define PLAYER_SIZE 0
#define PLAYER_TOP 0
#define PLAYER_BOTTOM 0

#define APPLE_SIZE_X 0
#define APPLE_SIZE_Y 0

void* Hit(int *p, int *a_x,int*a_y) {

	bool OnHit;

	//xy,�͒��S���W�Ƃ���
	int sx1 = *p;
	int sy1 = PLAYER_TOP;
	int sx2 = sx1 + PLAYER_SIZE;
	int sy2 = PLAYER_BOTTOM;

	int dx1 = *a_x;
	int dy1 = *a_y;
	int dx2 = dx1 + APPLE_SIZE_X;
	int dy2 = dy1 + APPLE_SIZE_Y;

	//�Z�`���d�Ȃ��Ă���Γ�����
	if (sx1 < dx2 && dx1 < sx2 && sy1 < dy2 && dy1 < sy2) {
		OnHit = TRUE;
	}
	else {
		OnHit = FALSE;
	}


	return (int*)OnHit;
}