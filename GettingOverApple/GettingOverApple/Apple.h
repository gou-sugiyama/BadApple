#pragma once
#define _USE_MATH_DEFINES
#include<math.h>
#define APPLE_MAX 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class APPLE {
protected:

	//変数
    int flg;
    int type;
	int x, y, w, h;
	int speed;
	int image;
	int point;
	
	//関数のプロトタイプ宣言
	void AppleControl(void);

	/*int LoadImages(void);*/
	APPLE();

	int GetRand(int RandMax);
public:
};
class NORMAL:public APPLE {
	int speed;
	int image;
public:
	NORMAL();
};

class BLUE:public APPLE {
	int speed;
	int image;
public:
	BLUE();
};

class GOLD:public APPLE {
	int speed;
	int image;
public:
	GOLD();
};

class POISON:public APPLE {
	int speed;
	int image;
public:
	POISON();
};