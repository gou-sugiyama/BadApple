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
	fp = fopen("", "r");

	//ファイルロード
	for (int i = 0; i < 5; i++) {
		rankdata[i] = new CRanking(fp);
	}
	//ファイルクローズ
	fclose(fp);

	WaitTime = 0;
	Type = 0;
	Str = 0;
	Count = 0;

	JudgeFlg = TRUE;

	for (int i = 0; i < STR_TYPE; i++) {
		for (int j = 0; j < STR_MAX; j++) {
			rankstr[i][j].str_X = j*30+60;
			rankstr[i][j].str_Y = i*60+80;
			rankstr[i][j].image = LoadGraph("images/Test.png");
			rankstr[i][j].bigimage = LoadGraph("images/Test2.png");
			rankstr[i][j].string = i * 26 + j;
			rankstr[i][j].strflg = FALSE;
		}
	}
	for (int i = 0; i < STR_TYPE; i++) {
		for (int j = 0; j < STR_MAX+2; j++) {
			rankcrsr[i][j].crsr_X = j;
			rankcrsr[i][j].crsr_Y = i;
		}
	}
}



int CRankMng::JudgeRanking() const
{
	for (int i = 4; i >= 0; i--) {
		if (rankdata[i - 1]->ShowRankScore() > ui->GetScore() > rankdata[i]->ShowRankScore()) {
			if (InsertJudge() == TRUE) {
				return i;
				break;
			}
		}
		else {
			
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
	int i;
	XINPUT_STATE data;
	data = controller->control(false);

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

	
	if (data.ThumbLX>=CONTROL_STICK)
	{
		if (0 < Str < STR_MAX/2|| STR_MAX/2 < Str < STR_MAX-1) {
			Str++;
		}
		else if (Str == 12) {
			Str = 0;
		}
		else if (Str == 25) {
			Str = 13;
		}else if (Str==26)
		{
			Str = 27;
		}
		else if (Str == 27) {
			Str = 26;
		}
	}
	else if (data.ThumbLX <= CONTROL_STICK*-1) {
		if (STR_MAX / 2 >Str > 0||STR_MAX-1 >Str> STR_MAX / 2) {
			Str--;
		}
		else if(Str==0){
			Str = 12;
		}
		else if (Str == 13) {
			Str = 25;
		}else if (Str==26)
		{
			Str = 27;
		}
		else if (Str == 27) {
			Str = 26;
		}
	}
	else if (data.ThumbLY>=CONTROL_STICK)
	{
		if (Str < STR_MAX/2) {
			Str = 26;
		}
		else if(STR_MAX / 2<= Str < STR_MAX) {
			Str = -13;
		}
		else if(Str==26||Str==27)
		{
			Str = 25;
		}
	}
	else if (data.ThumbLY >= CONTROL_STICK*-1)
	{
		if (Str < STR_MAX / 2) {
			Str + 13;
		}
		else if (STR_MAX / 2 <= Str < STR_MAX) {
			Str = 26;
		}
		else if (Str == 26 || Str == 27)
		{
			Str = 0;
		}
	}
	ToggleStrFlg(Type, Count);

	if (0 <= Str < STR_MAX) {
		if (Count > 9) {
			if (data.Buttons[XINPUT_BUTTON_A] == true) {
				RememberName[Count++] = rankstr[Type][Str].string;
			}
		}
		else {
			RememberName[9] = '\0';
		}
	}
	else if (Str == STR_MAX) {
		if (Type >= 2) {
			Type = 0;
		}
		else {
			Type++;
		}
	}
	else if (Str == STR_MAX + 1) {
		rankdata[i]->InsertRankChar(RememberName);
		ToggleJudge();
	}

	if (data.Buttons[XINPUT_BUTTON_B] == true) {
		RememberName[Count - 1] = '\0';
		Count--;
	}

}

void CRankMng::ToggleStrFlg(int i,int j)
{
	rankstr[i][j].strflg = !rankstr[i][j].strflg;
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
void CRankMng::Render() {
	if (JudgeRanking()!=-1) {
		
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 26; j++) {
				if (rankstr[i][j].strflg == TRUE) {
					DrawGraph(rankstr[i][j].str_X, rankstr[i][j].str_Y, rankstr[i][j].bigimage, TRUE);
					ToggleStrFlg(i,j);
				}
				else {
					DrawGraph(rankstr[i][j].str_X, rankstr[i][j].str_Y, rankstr[i][j].image, TRUE);
				}
			}
		}
		
	}
	else {
		if (WaitTime <= 240) {
			DrawString(0, 0, "ランキング表示", 0xFFFFFF);
		}
	}
	
}