#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define RANKING_DATA 5
#include"Apple.h"

RINGO apple;
////�萔�錾
//const int APPLE_MAX = 10;    //�����S�̍ő吔
//
////�ϐ�
//int g_apple[4];               //�����S�摜�ϐ�
//int g_AppleCount1, g_AppleCount2, g_AppleCount3,g_AppleCount4;     //�����S�J�E���g
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
////�����S
//struct APPLE g_Apple[APPLE_MAX];
//struct APPLE g_Apple00 = { TRUE,0,0,0,-50,58,120,0,1 };
//struct APPLE g_AppleCn = { TRUE, 4, 0, 0, -50, 18, 18, 0, 1 };
//struct APPLE g_AppleBike = { TRUE,3,0,0,-50,32,72,3,1 };
//
//struct APPLE g_item[APPLE_MAX];
//struct APPLE g_item00 = { TRUE,0,0,0,-50,50,50,0,1 };
//
////�֐��̃v���g�^�C�v�錾
//void AppleControl(void);
//int CreateApple(void);
RINGO::RINGO() {
	APPLE_MAX = 10;
}

/*
�����S�̈ړ�
�����F�Ȃ�
�߂�l�F�Ȃ�
*/
void RINGO::AppleControl(void) {
	for (int i = 0; i < APPLE_MAX; i++) {
		if (g_Apple[i].flg == TRUE) {
			//�G�̕\��
			DrawRotaGraph(g_Apple[i].x, g_Apple[i].y, 1.0f, 0, g_Apple[i].img, TRUE, FALSE);
			if (g_player.flg == FALSE)continue;

			if (g_Apple[i].type == 3) {
				//x��
				g_Apple[i].x = g_Apple[i].x + 7 * cos(raz);
				raz += 0.1;
				//y��
				g_Apple[i].y += g_Apple[i].speed + g_player.speed - PLAYER_SPEED + 1;
				//��ʂ��͂ݏo���������
				if (g_Apple[i].y > SCREEN_HEIGHT + g_Apple[i].h)g_enemy[i].flg = FALSE;
			}
			else {

				//�܂��������Ɉړ�
				g_Apple[i].y += g_Apple[i].speed + g_player.speed - PLAYER_SPEED + 1;
				//��ʂ��͂ݏo���������
				if (g_Apple[i].y > SCREEN_HEIGHT + g_Apple[i].h)g_Apple[i].flg = FALSE;
				//�G�@��ǂ��z������J�E���g����
				if (g_Apple[i].y > g_player.y && g_Apple[i].point == 1) {
					g_Apple[i].point = 0;
					if (g_Apple[i].type == 0)g_AppleCount1++;
					if (g_Apple[i].type == 1)g_AppleCount2++;
					if (g_Apple[i].type == 2)g_AppleCount3++;
				}
			}
			//�����蔻��
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
	//���s�������ƂɓE�o���p�^�[���𐧌䂷��
	if (g_Mileage / 10 % 50 == 0) {
		CreateApple();
	}
}

/*
�G�@�̐���
����:�Ȃ�
�߂�l:TRUE:�����@FALSE:���s
*/
int Apple::CreateApple(void) {
	for (int i = 0; i < APPLE_MAX; i++) {
		if (g_Apple[i].flg == FALSE) {
			g_Apple[i] = g_Apple00;
			g_Apple[i].type = GetRand(3);
			g_Apple[i].img = g_Apple[g_Apple[i].type];
			g_Apple[i].x = GetRand(4) * 105 + 40;
			g_Apple[i].speed = g_Apple[i].type * 2;
			//����
			return TRUE;
		}
	}
	return FALSE;
}