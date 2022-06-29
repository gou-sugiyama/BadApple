#include "Controller.h"


XINPUT_STATE CController::control(bool isChattering)
{

	if (isChattering) {


		GetJoypadXInputState(DX_INPUT_PAD1, &data);
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~oldKey.Buttons[i];
		}

		return data;

	}
	else {


		oldKey = input;
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~oldKey.Buttons[i];
		}
		data.LeftTrigger = input.LeftTrigger & ~oldKey.LeftTrigger;
		data.RightTrigger = input.RightTrigger & ~oldKey.RightTrigger;
		data.ThumbLX = input.ThumbLX & ~oldKey.ThumbLX;
		data.ThumbLY = input.ThumbLY & ~oldKey.ThumbLY;
		data.ThumbRX = input.ThumbRX & ~oldKey.ThumbRX;
		data.ThumbRY = input.ThumbRY & ~oldKey.ThumbRY;

		return data;

	}

}
