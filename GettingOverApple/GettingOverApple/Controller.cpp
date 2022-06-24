#include "Controller.h"



XINPUT_STATE Controller::Control()
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

	return data;
}

XINPUT_STATE Controller::PL_Control()
{
	GetJoypadXInputState(DX_INPUT_PAD1, &data);

	return data;
}

