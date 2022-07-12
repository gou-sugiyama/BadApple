#include"DxLib.h"
#include<stdio.h>
#include "SceneManager.h"
#include"Controller.h"
#include"RankMng.h"
#include "Ranking.h"
#include "UI.h"
#include"CString.h"


//--------------------------------
// コンストラクタ
//--------------------------------
CRankMng::CRankMng(CController* pController):CScene(pController) {
#pragma warning(disable:4996)
	//ファイルオープン
	fopen_s(&fp,"dat/rankingdata.txt", "r");

	//ファイルロード
	for (int i = 0; i < 5; i++) {
		int data1 = 0;
		char data2[9];
		int data3 = 0;
		fscanf_s(fp, "%2d %9s %10d", &data1, data2, 8, &data3);

		rankdata[i] = new CRanking(data1,data2,data3);
	}
	//ファイルクローズ
	fclose(fp);

	for (int i = 0; i < STR_MAX; i++) {
		StrData[i] = new CString(i);
	}

	Score = controller->GetScore();

	WaitTime = 0;
	Type = 0;
	Str = 13;
	Count = 0;

	JudgeFlg = TRUE;

	
}

CRankMng::~CRankMng()
{
	for (int i = 0; i < 5; i++) {
		delete rankdata[i];
	}
}



int CRankMng::JudgeRanking() const
{
	if (rankdata[4]->ShowRankScore() < Score) {
		if (InsertJudge() == TRUE) {
			return 4;
		}	
		else
		{
			return -1;
		}
	}

	return -1;
}


//--------------------------------
// 更新
//--------------------------------
CScene* CRankMng::Update() {
	//controller->control(false);
	if (JudgeRanking()!=-1) {
		TrueUpdate();
		return this;
	}
	else {
		if (FalseUpdate()) {
			return this;
		}
		else {
			return nullptr;
		}
	}
}

void CRankMng::TrueUpdate()
{
	int i;
	XINPUT_STATE data;
	data = controller->GetControl();

	i = JudgeRanking();
	InsertRanking(data,i);

}

bool CRankMng::InsertJudge() const
{
	return JudgeFlg;
}

void CRankMng::ToggleJudge()
{
	JudgeFlg = !(JudgeFlg);
}

void CRankMng::InsertRanking(XINPUT_STATE data,int i)
{
	
	for (int j = 0; j < STR_MAX; j++) {
		StrData[j]->SetStrFlg(FALSE);
	}
	
	if (data.ThumbLX>=CONTROL_STICK)
	{
		if (0 <= Str%13&&Str%13 < 13) {
			Str++;
		}
		else if (Str == 12) {
			Str -= 12;
		}
	}
	else if (data.ThumbLX <= CONTROL_STICK*-1) {
		if (12 >= Str&&Str > 0) {
			Str--;
		}
		else if(Str==0){
			Str += 12;
		}
	}
	else if (data.ThumbLY>=CONTROL_STICK)
	{
		if (Str < Str + 13) {
			Str += 13;
		}
	}
	else if (data.ThumbLY >= CONTROL_STICK*-1)
	{
		if (Str < Str-13) {
			Str -= 13;
		}
	}

	ToggleStrFlg(Str);

	if (0 <= Str&&Str < STR_MAX) {
		if (Count< 9) {
			if (data.Buttons[XINPUT_BUTTON_A] == TRUE) {
				RememberName[Count++] = StrData[Str]->GetStr();
			}
		}
		else {
			Count = 8;
		}
	}
	else if (Str == STR_MAX + 1) {
		rankdata[i]->InsertRankChar(RememberName);
		ToggleJudge();
	}

	if (data.Buttons[XINPUT_BUTTON_B] == TRUE) {
		RememberName[Count - 1] = '\0';
		Count--;
	}

}

void CRankMng::ToggleStrFlg(int i)
{
	StrData[i]->SetStrFlg(TRUE);
}

void CRankMng::SetScore(int i)
{
	Score = i;
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
void CRankMng::Render() const{
	if (JudgeRanking()!=-1) {
		
			for (int i = 0; i < STR_MAX; i++) {
				if (StrData[i]->GetStrFlg() == TRUE) {
					DrawGraph(StrData[i]->GetStrX(), StrData[i]->GetStrY(), StrData[i]->GetBigImage(), TRUE);
				}
				else {
					DrawGraph(StrData[i]->GetStrX(), StrData[i]->GetStrY(), StrData[i]->GetImage(), TRUE);
				}
			}
		
	}
	else {
		
			SetFontSize(28);
			DrawString(10, 10, "ランキング表示", 0xFFFFFF);
	
	}
	
}