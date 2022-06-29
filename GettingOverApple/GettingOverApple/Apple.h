#pragma once
#define _USE_MATH_DEFINES

#define APPLE_MAX 10
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
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return w; }
	int getH() { return h; }
	bool getisShow() { return isShow; };
};