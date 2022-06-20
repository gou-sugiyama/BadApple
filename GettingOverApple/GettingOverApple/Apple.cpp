#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Apple.h"
#include <stdlib.h>

APPLE::APPLE() {
	int x = GetRand(7);
	int y = 10;
	int h = 40;
	int w = 40;
	int flg = TRUE;
}

//if (LoadImages() == -1)return-1;      //画像読み込み関数を呼び出し

/*
リンゴの移動
引数：なし
戻り値：なし
*/
void APPLE::AppleControl(void) {
	for (int i = 0; i < APPLE_MAX; i++) {
		if (flg == TRUE) {
			//リンゴの表示
			DrawRotaGraph(x, y, 1.0f, 0, g_Apple.img, TRUE, FALSE);
			if (g_player.flg == FALSE)continue;

		    //まっすぐ下に移動
			y += speed;
		    //画面をはみ出したら消去
			if (y > SCREEN_HEIGHT + h)flg = FALSE;
			
		}
	}
}

NORMAL::NORMAL(){
	speed = 2;
	image = LoadGraph("images/Apple.jpg");
}
BLUE::BLUE() {
	speed = 5;
	image = LoadGraph("images/BlueApple.jpg");
}
GOLD::GOLD() {
	speed = 10;
    image = LoadGraph("images/GoldApple.jpg");
}
POISON::POISON() {
	speed = 1;
	image = LoadGraph("images/PoisonApple.jpg");
}

///*
//リンゴの生成
//引数:なし
//戻り値:TRUE:成功　FALSE:失敗
//*/
//int CreateEnemy(void) {
//	for (int i = 0; i < APPLE_MAX; i++) {
//		if (flg == FALSE) {
//			type = GetRand(3);
//			g_Apple[i].img = type;
//			x = GetRand(4) * 105 + 40;
//			//成功
//			return TRUE;
//		}
//	}
//	return FALSE;
//}