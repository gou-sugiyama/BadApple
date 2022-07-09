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


	//�t�@�C���I�[�v��
	fp = fopen("dat/chapter4/rankingdata.txt", "r");

	//�t�@�C�����[�h
	for (int i = 0; i < 5; i++) {
		rankdata[i] = new CRanking(fp);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}



bool CRankMng::JudgeRanking() const
{
	for (int i = 4; i >= 0; i--) {
		if (rankdata[i - 1]->ShowRankScore() > ui->GetScore() > rankdata[i]->ShowRankScore()) {
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
		if (FalseUpdate()) {
			return this;
		}
		else {
			return nullptr;
		}
	}
	
	return this;
}

void CRankMng::TrueUpdate()
{
	XINPUT_STATE data;
	data = controller->control(true);


	InsertRanking();

}

void CRankMng::InsertRanking()
{
	
}

bool CRankMng::FalseUpdate()
{
	if (++WaitTime <= 240) {
		return TRUE;
	}
	else {
		return FALSE;
	}

}

//--------------------------------
// �`��
//--------------------------------
void CRankMng::Render()const {
	if (JudgeRanking()) {
		DrawString(0, 0, "�����L���O����", 0xFFFFFF);
	}
	else if(WaitTime<=240){
		DrawString(0, 0, "�����L���O�\��", 0xFFFFFF);
	}
	
}