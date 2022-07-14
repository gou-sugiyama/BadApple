#pragma once
#include"DxLib.h"

#define APPLE_MAX 10

class CApple;
class CAppleManager
{
private:
	//‰æ‘œ•Ï”
	int WaitTime;
	/*int image1;
	int image2;
	int image3;
	int image4;*/
	int images1;
	int images2;
	int images3;
	int images4;

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