#include "Controller.h"

void Controller::Key()
{
	XINPUT_STATE input;

	if (controllerKey) {
		OldKey = NowKey;
		NowKey = GetJoypadXInputState(DX_INPUT_KEY_PAD1,&input);
		KeyFlg = NowKey & ~OldKey;
	}
	else
	{

	}
}
