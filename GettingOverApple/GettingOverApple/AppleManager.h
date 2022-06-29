#pragma once
class CApple;
class CAppleManager
{
private:
	int image;
	CApple* apple;
	
public:
	CAppleManager();
	~CAppleManager();
    void CreateApple();
	
	void Update();
	void Render()const;

	CApple* getpApple() { return apple; }
};