#include"DxLib.h"
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// コンストラクタ
//-----------------------
CApple::CApple() {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	image = LoadGraph("images/Apple_2.png");
	speed = 3;
	score = 0;
	isShow = false;
}

//------------------------
// 更新
//------------------------
void CApple::Update() {
	y += speed;
}

//------------------------
// リンゴの生成：初期化
//------------------------
void CApple::AppleInit(int type) {
	x = GetRand(6) * 71 + 35;
	y = 0;
	w = 40;
	h = 40;
	image = LoadGraph("images/Apple_2.png");
	speed = GetRand(9) + 1;
	score = 0;
	isShow = true;
}

//-------------------------
// 描画
//-------------------------
void CApple::Render()const {
	DrawGraph(x, y, image, TRUE);
}

