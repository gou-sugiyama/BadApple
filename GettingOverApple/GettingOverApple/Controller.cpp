#include "Controller.h"

CController::CController() {
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	oldKey = input;
	data = input;
}

void CController::Update() {
	oldKey = input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	data = input;
	for (int i = 0; i < MAX_BUTTON; i++) {
		data.Buttons[i] = input.Buttons[i] & ~oldKey.Buttons[i];
	}
}