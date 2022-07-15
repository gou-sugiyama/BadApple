#pragma once
#define D_STARTER_APPLE (4)
class CApple;
class CAppleManager
{
private:
	CApple* apple;
	
public:
	CAppleManager();
	~CAppleManager();
	
	void Update();
	void Render()const;
	CApple* GetpApple() { return apple; }
private:
    void CreateApple(int tasks);
	int CountApple();

};