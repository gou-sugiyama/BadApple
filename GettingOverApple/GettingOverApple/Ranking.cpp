#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include"Rank.h"
#include "Ranking.h"
#include "UI.h"



//--------------------------------
// コンストラクタ
//--------------------------------
CRankMane::CRankMane(CController* pController):CScene(pController) {
	for (int i = 0; i < 5; i++) {
		rankdata[i] = new CRanking(fp);

	}
}



bool CRankMane::JudgeRanking() const
{
	for (int i = 4; i >= 0; i--) {
		if (rankdata[i - 1]->ShowRankDeta() > ui->GetScore() > rankdata[i]->ShowRankDeta()) {
			return TRUE;
			break;
		}
		else {
			
		}
	}
	return FALSE;
}


//--------------------------------
// 更新
//--------------------------------
CScene* CRankMane::Update() {
	//controller->control(false);
	if (JudgeRanking()) {
		TrueUpdate();
	}
	else {
		FalseUpdate();
	}
	
}

void CRankMane::TrueUpdate()
{
	XINPUT_STATE data;
	for (int i = 1; i > 0;) {
		data = controller->control(true);

		InsertRanking();
	}
}

void CRankMane::InsertRanking()
{
}

void CRankMane::FalseUpdate()
{
}

//--------------------------------
// 描画
//--------------------------------
void CRankMane::Render()const {
	DrawString(0, 0, "ランキング入力", 0xFFFFFF);
}