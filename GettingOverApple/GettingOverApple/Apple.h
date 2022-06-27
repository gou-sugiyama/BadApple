#pragma once
#define _USE_MATH_DEFINES

#define APPLE_MAX 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define APPLE_WIDTH 40
#define APPLE_HEIGHT 40
class AppleManager;
class APPLE {
private:
	
	//int flg;
	int x;
	int y;
	//int h;
	//int w;
	int speed;
	int image;
	int score;
	bool isShow;

	/*int LoadImages(void);*/
public:
	//APPLE();
	APPLE(int pimage);
	
	//void CreateApple(void);
	//void AppleControl(void);
	//void AppleInit(void);
	void Update();
	void Render();
	void toggleisShow();
	int getY() { return y; };
	bool getisShow() { return isShow; };
	//int* App;
};

//class NORMAL:public APPLE {
//public:
//	NORMAL();
//};
//
//class BLUE:public APPLE {
//public:
//	BLUE();
//};
//
//class GOLD:public APPLE {
//public:
//	GOLD();
//};
//
//class POISON:public APPLE {
//public:
//	POISON();
//};

//class APPLE::public Object {
//	Manager* manager;
//	//ïœêî
//	APPLE(apple*);
//	~APPLE();
//
//	void AppleControl();
//};