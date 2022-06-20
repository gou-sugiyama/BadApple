#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

class RINGO {
public:
	//�萔�錾
	const int APPLE_MAX;    //�����S�̍ő吔 10��

	//�ϐ�
	int g_Apple[4];               //�����S�摜�ϐ�
	int g_AppleCount1, g_AppleCount2, g_AppleCount3, g_AppleCount4;     //�����S�J�E���g

	struct  APPLE {
		int flg;
		int type;
		int img;
		int x, y, w, h;
		int speed;
		int point;
	};

	//�֐��̃v���g�^�C�v�錾
	void AppleControl(void);
	int CreateApple(void);
	
private:
	//�����S
	struct APPLE g_Apple[APPLE_MAX];
	struct APPLE g_Apple00 = { TRUE,0,0,0,-50,58,120,0,1 };
	struct APPLE g_AppleCn = { TRUE, 4, 0, 0, -50, 18, 18, 0, 1 };
	struct APPLE g_AppleBike = { TRUE,3,0,0,-50,32,72,3,1 };

	struct APPLE g_item[APPLE_MAX];
	struct APPLE g_item00 = { TRUE,0,0,0,-50,50,50,0,1 };

public:
	RINGO(void);
	
}; extern RINGO apple;