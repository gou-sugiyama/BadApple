#include "Controller.h"



int Controller::Key()
{

	OldKey = input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	for (int i = 0; i < MAX_BUTTON; i++) {
		KeyFlg[i] = input.Buttons[i] & ~OldKey.Buttons[i];
	}

	return KeyFlg;
}

int Controller::BoolKey(enum data)
{
	if (input.ThumbLX == ) {

	}


	return 0;
}
