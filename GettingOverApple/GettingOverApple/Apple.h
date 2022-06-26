#pragma once
#define D_APPLE_WIDTH (40)
#define D_APPLE_HEIGHT (40)
class CAppleManager;
class CApple
{
private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int image;
	int speed;
	int score;
	bool isShow;
public:
	CApple(int pimage);
	void Update();
	void Render()const;
	void toggleisShow();
	int getY() { return m_y; }
	bool getisShow() { return isShow; }
};

