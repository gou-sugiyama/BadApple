#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include"Rank.h"
#include "Ranking.h"
#include "UI.h"



//--------------------------------
// コンストラクタ
//--------------------------------
CRankMng::CRankMng(CController* pController):CScene(pController) {


	//ファイルオープン
	fp = fopen("dat/chapter4/rankingdata.txt", "r");

	//ファイルロード
	for (int i = 0; i < 5; i++) {
		rankdata[i] = new CRanking(fp);
	}

	//ファイルクローズ
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
// 更新
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
// 描画
//--------------------------------
void CRankMng::Render()const {
	if (JudgeRanking()) {
		DrawString(0, 0, "ランキング入力", 0xFFFFFF);
	}
	else if(WaitTime<=240){
		DrawString(0, 0, "ランキング表示", 0xFFFFFF);
	}
	
}