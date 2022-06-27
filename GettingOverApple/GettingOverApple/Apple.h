#pragma once
#define _USE_MATH_DEFINES

#define APPLE_MAX 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define APPLE_WIDTH 40
#define APPLE_HEIGHT 40

class CAppleManager;
class CApple {
private:
	int x;
	int y;
	int w;
	int h;
	int speed;
	int image;
	int score;
	bool isShow;
public:
	CApple(int pimage);
	void Update();
	void Render();
	void toggleisShow();
	int getY() { return y; };
	bool getisShow() { return isShow; };
};