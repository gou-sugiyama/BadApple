#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// コンストラクタ
//-----------------------
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

//------------------------
// 更新
//------------------------
void CApple::Update() {
	y += speed;
}

//-------------------------
// 描画
//-------------------------
void CApple::Render()const {
	DrawGraph(x, y, image, TRUE);
}

