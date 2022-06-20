#include "Controller.h"

int Controller::Key(bool ControlFlg)
{
	XINPUT_STATE input;

	if (ControlFlg) {
		OldKey = NowKey;
		NowKey = GetJoypadXInputState(DX_INPUT_PAD1,&input);
		KeyFlg = NowKey & ~OldKey;
	}
	else
	{
		KeyFlg = GetJoypadXInputState(DX_INPUT_PAD1, &input);
	}

	return KeyFlg;
}
