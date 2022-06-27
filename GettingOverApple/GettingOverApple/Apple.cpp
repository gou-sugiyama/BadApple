#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"Apple.h"
#include"AppleManager.h"

APPLE::APPLE(int pimage) {
	x = GetRand(6) * 71 + 35;
	y = 0;
	/*h = 40;
	w = 40;*/
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

//if (LoadImages() == -1)return-1;      //画像読み込み関数を呼び出し

//void APPLE::AppleInit(void) {
//	
//	//リンゴの初期処理
//	for (int i = 0; i < 4; i++) {
//		flg = TRUE;
//
//		App = new int[10]{};
//		if (App == NULL){ 
//			*App = 4;
//		}
//		if (App != NULL) {
//			delete[]App;
//		}
//	}
//}

///*
//リンゴの移動
//引数：なし
//戻り値：なし
//*/
//void APPLE::AppleControl(void) {
//	
//		if (flg == TRUE) {
//
//			//リンゴの表示
//			DrawRotaGraph(x, y, 1.0f, 0, image, TRUE, FALSE);
//
//			//まっすぐ下に移動
//			y += speed;
//			//画面をはみ出したら消去
//			if (y > SCREEN_HEIGHT + h)flg = FALSE;
//			
//		}
//		if (flg == FALSE)APPLE::CreateApple();
//		
//	
//}

//NORMAL::NORMAL(){
//	speed = 2;
//	image = LoadGraph("images/Apple.jpg");
//	point = 150;
//}
//BLUE::BLUE() {
//	speed = 5;
//	image = LoadGraph("images/BlueApple.jpg");
//	point = 300;
//}
//GOLD::GOLD() {
//	speed = 10;
//    image = LoadGraph("images/GoldApple.jpg");
//	point = 500;
//}
//POISON::POISON() {
//	speed = 1;
//	image = LoadGraph("images/PoisonApple.jpg");
//	point = -1000;
//}

/*
リンゴの生成
引数:なし
戻り値:TRUE:成功　FALSE:失敗
*/
// void APPLE::CreateApple(void) {
//	 image = LoadGraph("images/Apple_2.png");
//
//	 Apple = new APPLE(image);
//	// int n = 0;
//	//for (int i = 0; i < n / 2; i++) {
//	//	for (int j = 0; j < n; j++) {
//	//		if (App[n] > App[n - 1]) {
//	//			j = App[n];
//	//			App[n] = App[n - 1];
//	//			App[n - 1] = n;
//	//		}
//	//	}
//	//}
//	//if (flg == FALSE) {
//	//	x = GetRand(6) * 71 + 35;
//	//	//成功
//
//	//}
//}

 //#include"AppleManager.h"

//APPLE::APPLE() {
//	x = GetRand(6) * 71 + 35;
//	y = 0;
//	h = 40;
//	w = 40;
//	//flg = TRUE;
//	speed = 3;
//	score = 0;
//	image = LoadGraph("images/Apple_2.png");
//	//int *App = 0;
//	//isShow = true;
//}
