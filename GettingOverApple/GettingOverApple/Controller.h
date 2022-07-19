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

	int Score;

	bool ControlFlg=TRUE;

public:
	XINPUT_STATE control(bool data);

	XINPUT_STATE GetControl() const;

	bool GetControlFlg() const;
	void ToggleControlFlg();

	void SetScore(int i) { Score = i; }
	int GetScore(){return Score;}
};
