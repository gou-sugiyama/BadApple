#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include"Rank.h"
#include "Ranking.h"
#include "UI.h"



//--------------------------------
// �R���X�g���N�^
//--------------------------------
CRankMng::CRankMng(CController* pController):CScene(pController) {
	for (int i = 0; i < 5; i++) {
		rankdata[i] = new CRanking(fp);

	}
}



bool CRankMng::JudgeRanking() const
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
// �X�V
//--------------------------------
CScene* CRankMng::Update() {
	//controller->control(false);
	if (JudgeRanking()) {
		TrueUpdate();
	}
	else {
		FalseUpdate();
	}
	
}

void CRankMng::TrueUpdate()
{
	XINPUT_STATE data;
	for (int i = 1; i > 0;) {
		data = controller->control(true);

		InsertRanking();
	}
}

void CRankMng::InsertRanking()
{
}

void CRankMng::FalseUpdate()
{
}

//--------------------------------
// �`��
//--------------------------------
void CRankMng::Render()const {
	DrawString(0, 0, "�����L���O����", 0xFFFFFF);
}