#pragma once
#define APPLE_MAX 10

class CApple;
class CAppleManager
{
private:
	int isShow;
public:
	
	CApple* Apple[10];
	CAppleManager();
	~CAppleManager();
    void CreateApple();
	void Update();
	void Render();

	CApple* getpApple(int i) { return Apple[i]; }
};