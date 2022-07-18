#pragma once
#include"DxLib.h"

#define APPLE_MAX 10
class CApple;
class CAppleManager
{
private:
	//‰æ‘œ•Ï”
	int WaitTime;
	int images[4];
	int AppleCount1;
	int AppleCount2;
	int AppleCount3;
	int count;

	CApple* Apple[10];

public:

	CAppleManager();
	~CAppleManager();
	void CreateApple();
	void Update();
	void Render() const;

	CApple* getpApple(int i) { return Apple[i]; }


	int GetImage(int i);
};