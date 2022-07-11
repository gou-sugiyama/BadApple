#pragma once
class CObject
{
protected:
	//‰æ‘œ
	int* image;
	//À•W
	float x;
	float y;

	//“–‚½‚è”»’è
	int width;
	int height;
	int rangeX;
	int rangeY;

public:
	virtual void HitAction() = 0;

};

void CheckHit(CObject* pObj1, CObject* pObj2);