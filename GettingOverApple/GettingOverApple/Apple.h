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
	int speed;        //移動速度
	int score;
	int type;         //種類
	int col;          //種類ごとの画像に表示される個数
	int image[4];
	bool appleFlg;

public:
	CApple();
	void Update();
	void Render() const;
	void toggleisShow();
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return w; }
	int getH() { return h; }
	int getSpeed() { return speed; }
	bool GetAppleFlg() { return appleFlg; };
};