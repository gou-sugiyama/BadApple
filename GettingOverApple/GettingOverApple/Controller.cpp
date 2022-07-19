#include "Controller.h"


void CController::control()
{
	OldKey = input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	data = input;
	for (int i = 0; i < MAX_BUTTON; i++) {
		data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
	}
}

XINPUT_STATE CController::GetControl() const
{
	return data;
}

