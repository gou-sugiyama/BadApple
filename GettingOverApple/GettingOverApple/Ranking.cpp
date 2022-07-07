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
// �R���X�g���N�^
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
// �X�V
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
// �`��
//--------------------------------
void CRankMane::Render()const {
	DrawString(0, 0, "�����L���O����", 0xFFFFFF);
}