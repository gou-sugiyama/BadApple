#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

#define APPLE_MAX 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class APPLE {
protected:
	
	int flg;
	int x;
	int y;
	int h;
	int w;
	int speed;
	int image;
	int point;
	

	/*int LoadImages(void);*/
public:
	APPLE();
	
	void CreateApple(void);
	void AppleControl(void);
	void AppleInit(void);
	
	int* App;
	
	int n;
};

class NORMAL:public APPLE {
public:
	NORMAL();
};

class BLUE:public APPLE {
public:
	BLUE();
};

class GOLD:public APPLE {
public:
	GOLD();
};

class POISON:public APPLE {
public:
	POISON();
};

//class APPLE::public Object {
//	Manager* manager;
//	//ïœêî
//	APPLE(apple*);
//	~APPLE();
//
//	void AppleControl();
//};