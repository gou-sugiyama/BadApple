#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

CApple::CApple(int pimage) {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	image = pimage;
	speed = 3;
	score = 0;
	isShow = true;
}

void CApple::Update() {
	y += speed;
}

void CApple::Render() {
	DrawGraph(x, y, image, TRUE);
}

void CApple::toggleisShow() {
	isShow = !isShow;
}
