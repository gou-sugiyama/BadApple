#pragma once
#include"DxLib.h"

#define CONTROL_X_RIGHT 25000
#define CONTROL_X_LEFT -25000

bool controllerKey;

XINPUT_STATE input;

enum Controll
{
	
};


class Controller
{
private:
	int OldKey;
	int NowKey;
	int KeyFlg;


public:
	int Key(bool ControlFlg);
	int BoolKey(enum  data);
};

