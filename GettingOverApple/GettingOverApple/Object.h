#pragma once
class CObject
{
public:
	//�摜
	int* image = 0;
	//���W
	float x = 0;
	float y = 0;

	//�����蔻��
	int width = 0;
	int height = 0;
	int rangeX = 0; 
	int rangeY = 0;

public:
	CObject() {}
	virtual void HitAction() = 0;


};

void CheckHit(CObject* pObj1, CObject* pObj2);