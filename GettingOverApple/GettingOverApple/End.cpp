#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {
	image = LoadGraph("images/haikei.png");
}

//--------------------------------
// 更新
//--------------------------------
CScene* CEnd::Update() {
	static int limit = 180;

	if (limit-- < 0) {
		return nullptr;
	}
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CEnd::Render()const {
	DrawGraph(0, 0, image, FALSE);
}