#pragma once

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
	void Render()const;
	void ToggleisShow() { isShow = !isShow; }
	int GetX() { return x; }
	int GetY() { return y; }
	int GetW() { return w; }
	int GetH() { return h; }
	bool GetisShow() { return isShow; };
};