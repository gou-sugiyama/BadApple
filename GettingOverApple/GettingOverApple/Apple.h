#pragma once
#define _USE_MATH_DEFINES

#define APPLE_WIDTH 40
#define APPLE_HEIGHT 40
#define SPEED_1 2
#define SPEED_2 5
#define SPEED_3 10
#define SPEED_4 1
#define APPLE_MAX 10

class CAppleManager;
class CApple {
private:
	int x;
	int y;
	int w;
	int h;
	int speed;        //ˆÚ“®‘¬“x
	int image[4];     //‰æ‘œ•Ï”
	int score;
	int type;         //í—Ş
	int col;          //í—Ş‚²‚Æ‚Ì‰æ‘œ‚É•\¦‚³‚ê‚éŒÂ”
	bool isShow;
public:
	CApple();
	void Update();
	void Render();
	void toggleisShow();
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return w; }
	int getH() { return h; }
	int getSpeed() { return speed; }
	bool getisShow() { return isShow; };
};