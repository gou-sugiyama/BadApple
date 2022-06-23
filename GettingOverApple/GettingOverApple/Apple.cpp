#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include"Apple.h"
#include <stdlib.h>
#include"Object.h"
#include"AppleManager.h"
#include<process.h>
//#include"AppleManager.h"



APPLE::APPLE() {
	x = GetRand(6) * 71 + 35;
	y = 10;
	h = 40;
	w = 40;
	flg = TRUE;
	speed = 3;
	point = 0;
	image = LoadGraph("images/Apple_2.png");
	App = 0;
	n = 0;
}
//APPLE::~APPLE() {
//
//}

//if (LoadImages() == -1)return-1;      //�摜�ǂݍ��݊֐����Ăяo��

void APPLE::AppleInit(void) {
	
	*App = 4;
	//�����S�̏�������
	for (int i = 0; i < *App; i++) {
		flg = TRUE;

		App = new int[10]{};
		if (App == NULL) {
			*App = 4;
		}
		if (App != NULL) {
			delete[]App;
		}
	}
}

/*
�����S�̈ړ�
�����F�Ȃ�
�߂�l�F�Ȃ�
*/
void APPLE::AppleControl(void) {
	
		if (flg == TRUE) {

			//�����S�̕\��
			DrawRotaGraph(x, y, 1.0f, 0, image, TRUE, FALSE);

			//�܂��������Ɉړ�
			y += speed;
			//��ʂ��͂ݏo���������
			if (y > SCREEN_HEIGHT + h)flg = FALSE;
			
		}
		if (flg == FALSE)APPLE::CreateApple();
		
	
}

NORMAL::NORMAL(){
	speed = 2;
	image = LoadGraph("images/Apple.jpg");
	point = 150;
}
BLUE::BLUE() {
	speed = 5;
	image = LoadGraph("images/BlueApple.jpg");
	point = 300;
}
GOLD::GOLD() {
	speed = 10;
    image = LoadGraph("images/GoldApple.jpg");
	point = 500;
}
POISON::POISON() {
	speed = 1;
	image = LoadGraph("images/PoisonApple.jpg");
	point = -1000;
}

/*
�����S�̐���
����:�Ȃ�
�߂�l:TRUE:�����@FALSE:���s
*/
 void APPLE::CreateApple(void) {
	 
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			if (App[n] > App[n - 1]) {
				j = App[n];
				App[n] = App[n - 1];
				App[n - 1] = n;
			}
		}
	}
	if (flg == FALSE) {
		x = GetRand(6) * 71 + 35;
		//����

	}
}

//void Object::CreateApple() {
//	if (apple.flg == TRUE) {
//
//		//�����S�̕\��
//		DrawRotaGraph(x, y, 1.0f, 0, apple.image, TRUE, FALSE);
//
//		//�܂��������Ɉړ�
//		y += apple.speed;
//		//��ʂ��͂ݏo���������
//		if (y > SCREEN_HEIGHT + apple.h)apple.flg = FALSE;
//
//	}
//	APPLE::CreateApple();
//}