#include "Controller.h"



int Controller::Key(bool ControlFlg)
{

	if (ControlFlg) {			//TRUE:�������j�~
		OldKey = NowKey;
		NowKey = GetJoypadXInputState(DX_INPUT_PAD1,&input);
	}
	else
	{							//FALSE:����������
		
		if (input.ThumbLX!=128) {
			OldKey = KeyFlg;
			KeyFlg = input.ThumbLX;
			
		}
		else if(input.Buttons[5]!=FALSE) {
			KeyFlg = GetJoypadXInputState(DX_INPUT_PAD1, &input);
		}
		
	}

	return KeyFlg;
}

int Controller::BoolKey(enum data)
{
	if (input.ThumbLX == ) {

	}


	return 0;
}
