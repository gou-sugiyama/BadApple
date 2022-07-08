#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {

}

//--------------------------------
// 更新
//--------------------------------
CScene* CEnd::Update() {
	//controller->control(false);
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CEnd::Render()const {
	DrawString(0, 0, "エンド画面", 0xFFFFFF);
}