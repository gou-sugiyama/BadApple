#pragma once
#define APPLE_MAX 10

class CApple;
class CAppleManager
{
private:

	int image[4];     //‰æ‘œ•Ï”
	int WaitTime;


	CApple* Apple[10];

public:
	
	CAppleManager();
	~CAppleManager();
    void CreateApple();
	void Update();
	void Render() const;

	int GetImage(int i);
	CApple* getpApple(int i) { return Apple[i]; }
};