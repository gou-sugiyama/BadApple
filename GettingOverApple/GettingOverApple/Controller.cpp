#include "Controller.h"


XINPUT_STATE Controller::control()
{

	if (controllerKey) {


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
	else {


		GetJoypadXInputState(DX_INPUT_PAD1, &data);
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
		}

		return data;

	}

}
