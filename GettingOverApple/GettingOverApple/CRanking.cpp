#include "SceneManager.h"
#include "CRanking.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CRanking::CRanking(CController* pController) :CScene(pController) {

}

//--------------------------------
// 更新
//--------------------------------
CScene* CRanking::Update() {
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CRanking::Render()const {

}