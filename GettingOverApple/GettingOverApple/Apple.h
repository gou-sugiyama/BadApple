#pragma once
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
public:
	CApple();
	void Draw()const;
	void Fall();
};

