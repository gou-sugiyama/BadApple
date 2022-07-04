#pragma once
class APPLE;
class AppleManager
{
private:
	int image[4];
	int isShow;
	APPLE* Apple;
public:
	AppleManager();
	~AppleManager();
    bool CreateApple();

	void Update();
	void Render();
};