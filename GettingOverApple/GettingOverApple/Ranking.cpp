#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include"Rank.h"
#include "Ranking.h"
#include "UI.h"

void CRankMane::InitRank(int i)
{
	fscanf(fp, "%2d %10s %10d", rankdata[i]->InsertRanking());
}

//--------------------------------
// コンストラクタ
//--------------------------------
CRankMane::CRankMane(CController* pController):CScene(pController) {
	for (int i = 0; i < 5; i++) {
		rankdata[i] = new CRanking(i);

	}
}


bool CRankMane::JudgeRanking(int i)
{
	bool judge;
	if (rank->ShowRankDeta(i - 1) > ui->GetScore() > rank->ShowRankDeta(i)) {
		return TRUE;
	}
	else {
		return FALSE;
	}
	
}


//--------------------------------
// 更新
//--------------------------------
CScene* CRankMane::Update() {
	//controller->control(false);
	/*for (int i = 4; i >= 0; i--) {
		if (JudgeRanking(i)) {
			return ;
		}
	}*/
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CRankMane::Render()const {
	DrawString(0, 0, "ランキング入力", 0xFFFFFF);
}