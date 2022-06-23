#pragma once
class CApple;
class CAppleManager
{
private:
	int image;
	CApple* Apple;

public:
	CAppleManager();
	~CAppleManager();
	bool CreateApple();

	void Update();
	void Render();
};

