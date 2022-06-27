#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

APPLE::APPLE(int pimage) {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	image = pimage;
	speed = 3;
	score = 0;
	isShow = true;
}

void APPLE::Update() {
	y += speed;
}

void APPLE::Render() {
	DrawGraph(x, y, image, TRUE);
}

void APPLE::toggleisShow() {
	isShow = !isShow;
}
