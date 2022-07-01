#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "Ranking.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CRanking::CRanking(CController* pController) :CScene(pController) {

}

//--------------------------------
// 更新
//--------------------------------
CScene* CRanking::Update() {
	//controller->control(false);
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CRanking::Render()const {
	DrawString(0, 0, "ランキング入力", 0xFFFFFF);
}