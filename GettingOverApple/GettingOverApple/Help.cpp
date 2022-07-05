#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "Help.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CHelp::CHelp(CController* pController) :CScene(pController) {

}

//--------------------------------
// 更新
//--------------------------------
CScene* CHelp::Update() {
	//controller->control(false);
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CHelp::Render()const {
	DrawString(0, 0, "ヘルプ画面", 0xFFFFFF);
}