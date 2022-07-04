#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Controller.h"
#include"Game.h"

CScene* CTitle::Update() {
	if ((controller->control(false)).Buttons[4] == true) {
		//ゲームシーンに移行
		return new CGame(controller);
	}
	return this;
}

void CTitle::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトル");
}
