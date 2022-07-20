#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {
	EndImage = LoadGraph("images/End.png");
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
	DrawGraph(0,0,EndImage, FALSE);
}