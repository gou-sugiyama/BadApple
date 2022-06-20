#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define RANKING_DATA 5
#include"Apple.h"

RINGO apple;
////定数宣言
//const int APPLE_MAX = 10;    //リンゴの最大数
//
////変数
//int g_apple[4];               //リンゴ画像変数
//int g_AppleCount1, g_AppleCount2, g_AppleCount3,g_AppleCount4;     //リンゴカウント
//
//struct  APPLE {
//	int flg;
//	int type;
//	int img;
//	int x, y, w, h;
//	int speed;
//	int point;
//};
//
////リンゴ
//struct APPLE g_Apple[APPLE_MAX];
//struct APPLE g_Apple00 = { TRUE,0,0,0,-50,58,120,0,1 };
//struct APPLE g_AppleCn = { TRUE, 4, 0, 0, -50, 18, 18, 0, 1 };
//struct APPLE g_AppleBike = { TRUE,3,0,0,-50,32,72,3,1 };
//
//struct APPLE g_item[APPLE_MAX];
//struct APPLE g_item00 = { TRUE,0,0,0,-50,50,50,0,1 };
//
////関数のプロトタイプ宣言
//void AppleControl(void);
//int CreateApple(void);
RINGO::RINGO() {
	APPLE_MAX = 10;
}

/*
リンゴの移動
引数：なし
戻り値：なし
*/
void RINGO::AppleControl(void) {
	for (int i = 0; i < APPLE_MAX; i++) {
		if (g_Apple[i].flg == TRUE) {
			//敵の表示
			DrawRotaGraph(g_Apple[i].x, g_Apple[i].y, 1.0f, 0, g_Apple[i].img, TRUE, FALSE);
			if (g_player.flg == FALSE)continue;

			if (g_Apple[i].type == 3) {
				//x軸
				g_Apple[i].x = g_Apple[i].x + 7 * cos(raz);
				raz += 0.1;
				//y軸
				g_Apple[i].y += g_Apple[i].speed + g_player.speed - PLAYER_SPEED + 1;
				//画面をはみ出したら消去
				if (g_Apple[i].y > SCREEN_HEIGHT + g_Apple[i].h)g_enemy[i].flg = FALSE;
			}
			else {

				//まっすぐ下に移動
				g_Apple[i].y += g_Apple[i].speed + g_player.speed - PLAYER_SPEED + 1;
				//画面をはみ出したら消去
				if (g_Apple[i].y > SCREEN_HEIGHT + g_Apple[i].h)g_Apple[i].flg = FALSE;
				//敵機を追い越したらカウントする
				if (g_Apple[i].y > g_player.y && g_Apple[i].point == 1) {
					g_Apple[i].point = 0;
					if (g_Apple[i].type == 0)g_AppleCount1++;
					if (g_Apple[i].type == 1)g_AppleCount2++;
					if (g_Apple[i].type == 2)g_AppleCount3++;
				}
			}
			//当たり判定
			if (HitBoxPlayer(&g_player, &g_Apple[i]) == TRUE && g_player.baricnt <= 0) {
				g_player.flg = FALSE;
				g_player.speed = PLAYER_SPEED;
				g_player.count = 0;
				g_player.hp -= 100;
				g_Apple[i].flg = FALSE;
				if (g_player.hp <= 0)g_GameState = 6;
			}

		}
	}
	//走行距離ごとに摘出現パターンを制御する
	if (g_Mileage / 10 % 50 == 0) {
		CreateApple();
	}
}

/*
敵機の生成
引数:なし
戻り値:TRUE:成功　FALSE:失敗
*/
int Apple::CreateApple(void) {
	for (int i = 0; i < APPLE_MAX; i++) {
		if (g_Apple[i].flg == FALSE) {
			g_Apple[i] = g_Apple00;
			g_Apple[i].type = GetRand(3);
			g_Apple[i].img = g_Apple[g_Apple[i].type];
			g_Apple[i].x = GetRand(4) * 105 + 40;
			g_Apple[i].speed = g_Apple[i].type * 2;
			//成功
			return TRUE;
		}
	}
	return FALSE;
}