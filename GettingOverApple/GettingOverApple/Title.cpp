#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"
#include"Controller.h"
#include"Game.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CTitle::CTitle(CController* pController) :CScene(pController) {

}

//--------------------------------
// 更新
//--------------------------------
CScene* CTitle::Update() {
	if (controller->control(false).Buttons[4]) {
		//ゲームシーンに移行
		return new CGame(controller);
	}
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CTitle::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "タイトル");
}
