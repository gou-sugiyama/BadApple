#include "Controller.h"


void CController::control(bool isChattering)
{

	if (!isChattering) {


		OldKey = input;
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
		}
		data.LeftTrigger = input.LeftTrigger & ~OldKey.LeftTrigger;
		data.RightTrigger = input.RightTrigger & ~OldKey.RightTrigger;
		if (OldKey.ThumbLX == input.ThumbLX) {
			FlgCount = 1;
			data.ThumbLX = input.ThumbLX;
		}

		if (FlgCount == 1) {
			FlgCount = 0;
			data.ThumbLX = input.ThumbLX & ~OldKey.ThumbLX;
		}

		data.ThumbLY = input.ThumbLY & ~OldKey.ThumbLY;
		data.ThumbRX = input.ThumbRX & ~OldKey.ThumbRX;
		data.ThumbRY = input.ThumbRY & ~OldKey.ThumbRY;

	}
	else {

		OldKey = input;
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		data = input;
		for (int i = 0; i < MAX_BUTTON; i++) {
			data.Buttons[i] = input.Buttons[i] & ~OldKey.Buttons[i];
		}

	}

}


XINPUT_STATE CController::GetControl() const
{
	return data;
}

bool CController::GetControlFlg() const
{
	return ControlFlg;
}

void CController::ToggleControlFlg()
{
	ControlFlg = !(ControlFlg);
}

void CController::SetScore(int data)
{
	Score = data;
}

int CController::GetScore()
{
	return Score;
}
