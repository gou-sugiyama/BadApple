#include"Apple.h"
#include"AppleManager.h"

CAppleManager applemng;

CApple::CApple(int i) {
	x = GetRand(6) * 70 + 35;
	y = -40;
	w = 40;
	h = 40;
	score = 0;
	appleFlg = TRUE;
	image = i;
	type = i;
	col = i;
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
	DrawGraph(x, y,image,TRUE);
}

void CApple::toggleisShow() {
	appleFlg = !appleFlg;
}

