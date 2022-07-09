#pragma once
#define APPLE_MAX 10

class CApple;
class CAppleManager
{
private:
	int isShow;
public:
	int image[4];
	CApple* Apple[10];
	CAppleManager();
	~CAppleManager();
    void CreateApple();
	void ControlApple();
	void Update();
	void Render();

	CApple* getpApple(int i) { return Apple[i]; }
};