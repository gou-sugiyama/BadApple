#pragma once
#include"DxLib.h"

bool controllerKey;

class Controller
{
private:
	int OldKey;
	int NowKey;
	int KeyFlg;


public:
	void Key();
};

