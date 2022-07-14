#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

CAppleManager applemng;

CApple::CApple() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	score = 0;
	appleFlg = TRUE;

	image[0] = LoadGraph("images/Apple_2.png");
	image[1] = LoadGraph("images/BlueApple4.png");
	image[2] = LoadGraph("images/GoldApple.png");
	image[3] = LoadGraph("images/PoisonApple.png");


	col = GetRand(9);
	type = GetRand(3);
	if (0 <= col && col <= 5) {
		type = 0;
	}
	else if (6 <= col && col <= 7) {
		type = 1;
	}
	else if (col == 8) {
		type = 2;
	}
	else {
		type = 3;
	}

	if (type == 0) {
		speed = 2;
	}
	else if (type == 1) {
		speed = 4;
	}
	else if (type == 2) {
		speed = 7;
	}
	else {
		speed = 1;
	}
	

}

void CApple::Update() {
	y += speed;
}

void CApple::Render() const {

	DrawGraph(x, y,image[type],TRUE);
}

void CApple::toggleisShow() {
	appleFlg = !appleFlg;
}
