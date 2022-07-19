#pragma once
#include"DxLib.h"
#include"player.h"
#include"Apple.h"

#define CONTROL_STICK 25000
#define MAX_BUTTON 16

class CController
{
private:
	int Score;

	XINPUT_STATE input;
	XINPUT_STATE OldKey;
	XINPUT_STATE data;

	bool ControlFlg=FALSE;

	int FlgCount;

public:
	void control(bool data);

	XINPUT_STATE GetControl() const;

	bool GetControlFlg() const;
	int GetFlgCount() { return FlgCount; }
	void ToggleControlFlg();

	void SetScore(int data);
	int GetScore();
};


void* Hit(CPlayer* pPlayer, CApple* pApple);

