#pragma once
#include"Object.h"

#define D_APPLE_MAX 10
#define D_APPLE_WIDTH 40
#define D_APPLE_HEIGHT 40
#define D_APPLE_A 0
#define D_APPLE_B 1
#define D_APPLE_C 2
#define D_APPLE_D 3
#define D_APPLE_A_SPEED 2
#define D_APPLE_B_SPEED 5
#define D_APPLE_C_SPEED 10
#define D_APPLE_D_SPEED 1
#define D_APPLE_A_SCORE 150
#define D_APPLE_B_SCORE 300
#define D_APPLE_C_SCORE 500
#define D_APPLE_D_SCORE -1000 
#define D_PROPORTION_A 6
#define D_PROPORTION_B D_PROPORTION_A + 2
#define D_PROPORTION_C D_PROPORTION_B + 1
#define D_PROPORTION_D D_PROPORTION_C + 1
#define D_CREATE_POINT_NUM 7
#define D_APPLE_IMAGE_MAX 4

class CAppleManager;
class CApple : 
	public CObject {
private:
	int speed;
	int imgHandle;
	int score;
	bool isShow;
public:
	CApple();
	~CApple();
	void Update();
	void NewApple(float x);
	void CreateAppleA(float x);
	void CreateAppleB(float x);
	void CreateAppleC(float x);
	void CreateAppleD(float x);

	void Render()const;

	void HitAction();

	void ToggleisShow() { isShow = !isShow; }
	float GetX() { return x; }
	float GetY() { return y; }
	int GetS() { return speed; }
	int GetType() { return imgHandle; }
	int GetScore() { return score; }
	bool GetisShow() { return isShow; };
};