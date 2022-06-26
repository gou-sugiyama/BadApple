#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Game.h"

CScene* CTitle::Update() {
	if (*(manager->GetKey()) >= 1) {
		//ゲームシーンに移行
		return new CGame(manager);
	}
	return this;
}

void CTitle::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトル");
}
