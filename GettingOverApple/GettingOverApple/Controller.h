#pragma once
#include"DxLib.h"
#include"player.h"
#include"Apple.h"

#define CONTROL_X_RIGHT 25000
#define CONTROL_X_LEFT -25000
#define MAX_BUTTON 16

class CController
{
private:
	XINPUT_STATE input;
	XINPUT_STATE oldKey;
	XINPUT_STATE data;
public:
	XINPUT_STATE control(bool isChattering);
};
