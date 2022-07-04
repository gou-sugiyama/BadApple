#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

APPLE::APPLE(int pimage) {
	x = GetRand(6) * 71 + 35;
	y = 40;
	w = 40;
	h = 40;
	image[4] = pimage;
	speed = 3;
	score = 0;
	isShow = true;
}

void APPLE::Update() {
	y += speed;
}

void APPLE::Render() {
	DrawGraph(x, y, image[4], TRUE);
}

void APPLE::toggleisShow() {
	isShow = !isShow;
}
