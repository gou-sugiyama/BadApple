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
	XINPUT_STATE data;

	short stick;


public:

	XINPUT_STATE Control();
	XINPUT_STATE PL_Control();
};

