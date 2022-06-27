#pragma once
class APPLE;
class AppleManager
{
private:
	int image;
	APPLE* Apple;
	//APPLE* apple[APPLE_MAX];
public:
	AppleManager();
	~AppleManager();
    bool CreateApple();
	
	void Update();
	void Render();
};