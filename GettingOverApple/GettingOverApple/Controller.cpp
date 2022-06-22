#include "Controller.h"



void Controller::Control(XINPUT_STATE &data)
{
	OldKey = input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	for (int i = 0; i < MAX_BUTTON; i++) {
		data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
	}
	data.LeftTrigger = input.LeftTrigger & ~OldKey.LeftTrigger;
	data.RightTrigger = input.RightTrigger & ~OldKey.RightTrigger;
	data.ThumbLX = input.ThumbLX & ~OldKey.ThumbLX;
	data.ThumbLY = input.ThumbLY & ~OldKey.ThumbLY;
	data.ThumbRX = input.ThumbRX & ~OldKey.ThumbRX;
	data.ThumbRY = input.ThumbRY & ~OldKey.ThumbRY;
}

void Controller::PL_Control(XINPUT_STATE &input)
{
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
}

