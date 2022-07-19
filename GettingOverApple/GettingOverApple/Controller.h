#pragma once
#include"DxLib.h"
#include"player.h"
#include"Apple.h"

#define CONTROL_STICK 25000
#define MAX_BUTTON 16

class CController
{
private:
	XINPUT_STATE input;
	XINPUT_STATE OldKey;
	XINPUT_STATE data;
public:
	void control();

	XINPUT_STATE GetControl() const;

};


void* Hit(CPlayer* pPlayer, CApple* pApple);

