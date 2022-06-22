#pragma once
#include"DxLib.h"

#define CONTROL_X_RIGHT 25000
#define CONTROL_X_LEFT -25000
#define MAX_BUTTON 16

bool controllerKey;



enum Controll
{
	
};


class Controller
{
private:
	XINPUT_STATE input;
	XINPUT_STATE OldKey;
	unsigned char KeyFlg[16];
	short stick;


public:

	void Control(XINPUT_STATE &data);
	void PL_Control(XINPUT_STATE &input);
};

