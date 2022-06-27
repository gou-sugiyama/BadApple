#pragma once
class APPLE;
class AppleManager
{
private:
	int image;
	APPLE* Apple;
public:
	AppleManager();
	~AppleManager();
    bool CreateApple();
	
	void Update();
	void Render();
};