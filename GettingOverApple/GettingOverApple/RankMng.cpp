#include<stdio.h>
#include"Controller.h"
#include"RankMng.h"
#include<string>

//--------------------------------
// コンストラクタ
//--------------------------------
CRankMng::CRankMng(CController* pController):CScene(pController) {
#pragma warning(disable:4996)
	//ファイルオープン
	fopen_s(&fp,"dat/rankingdata.txt", "r");

	//ファイルロード
	for (int i = 0; i < 5; i++) {
		fscanf_s(fp, "%2d %9s %10d", &rankdata[i].Rank,rankdata[i].Name, 8, &rankdata[i].Score);
	}
	//ファイルクローズ
	fclose(fp);

	for (int i = 0; i < STR_MAX; i++) {
		StrData[i] = new CString(i);
	}

	Score = controller->GetScore();

	WaitTime = 0;
	Type = 0;
	Str = 0;
	Count = 0;

	JudgeFlg = TRUE;

	controller->ToggleControlFlg();
}

CRankMng::~CRankMng()
{
}



int CRankMng::JudgeRanking() const
{
	if (rankdata[4].Score < Score) {
		if (JudgeFlg == TRUE) {
			return 1;
		}
		else {

			return -1;
		}
	}
	else{
		return -1;
	}
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
			controller->ToggleControlFlg();
			return nullptr;
		}
	}
}

void CRankMng::TrueUpdate()
{
	data = controller->GetControl();

	ControlRanking(data);

}

void CRankMng::ToggleJudge()
{
	JudgeFlg = !(JudgeFlg);
}

void CRankMng::ControlRanking(XINPUT_STATE data)
{
	
	int Cntller = DelayCNTL();

	for (int j = 0; j < STR_MAX; j++) {
		StrData[j]->SetStrFlg(FALSE);
	}
	
	if (data.Buttons[XINPUT_BUTTON_DPAD_RIGHT]|| Cntller ==1)
	{
		if (0 <= Str%13&&Str%13 < 12) {
			Str++;
			FlgCount = 1;
		}
		else if (Str%13 == 12) {
			Str -= 12;
			FlgCount = 1;
		}

	}
	else {
		FlgCount = 0;
	}
	if (data.Buttons[XINPUT_BUTTON_DPAD_LEFT] || Cntller == 2) {
		if (12 >= Str%13&&Str%13 > 0) {
			Str--;
		}
		else if(Str%13==0){
			Str += 12;
		}
	}
	if (data.Buttons[XINPUT_BUTTON_DPAD_DOWN] || Cntller == 3)
	{
		if (Str+13 < STR_MAX ) {
			Str += 13;
		}
	}
	if (data.Buttons[XINPUT_BUTTON_DPAD_UP] || Cntller == 4)
	{
		if (Str-13 >= 0) {
			Str -= 13;
		}
	}

	SetStrImageFlg(Str);

	if (0 <= Str&&Str < STR_MAX-1&& data.Buttons[XINPUT_BUTTON_A]) {
		if (Count< 9) {
				RememberName[Count++] = StrData[Str]->GetStr();
		}
		else {
			Count = 9;
		}
	}

	if (Str == STR_MAX-1&&data.Buttons[XINPUT_BUTTON_A]) {
		InsertRankChar(RememberName);
		ToggleJudge();
	}

	if (data.Buttons[XINPUT_BUTTON_B]) {
		if (Count > 0) {
			RememberName[Count - 1] = '\0';
			Count--;
		}
		else {

		}
	}

}

void CRankMng::SetStrImageFlg(int i)
{
	StrData[i]->SetStrFlg(TRUE);
}

void CRankMng::SetScore(int i)
{
	Score = i;
}

void CRankMng::InsertRankChar(char* data1)
{
	strcpy(rankdata[4].Name, data1);
	rankdata[4].Score = this->Score;
}

void CRankMng::SortRanking()
{
	int work;
	char SaveStorage[9];
	// 選択法ソート
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (rankdata[i].Score <= rankdata[j].Score) {
				work = rankdata[i].Score;
				strcpy(SaveStorage, rankdata[i].Name);
				rankdata[i].Score = rankdata[j].Score;
				strcpy(rankdata[i].Name, rankdata[j].Name);
				rankdata[j].Score = work;
				strcpy(rankdata[j].Name, rankdata[i].Name);
			}
		}
	}

	// 順位付け
	for (int i = 0; i < 4; i++) {
		rankdata[i].Rank = 1;
	}
}

int CRankMng::DelayCNTL()
{
	if (CntlTime++ % 30==0) {
		if (data.ThumbLX > CONTROLLER_STICK_MAX) {
			kanning = 1;
		}
		if (data.ThumbLX < -CONTROLLER_STICK_MAX - 1) {
			kanning = 2;
		}
		if (data.ThumbLY < -CONTROLLER_STICK_MAX - 1) {
			kanning = 3;
		}
		if (data.ThumbLY > CONTROLLER_STICK_MAX) {
			kanning = 4;
		}
		if (data.ThumbLX < CONTROLLER_STICK_MAX&& data.ThumbLX > -CONTROLLER_STICK_MAX
			&& data.ThumbLY < CONTROLLER_STICK_MAX&& data.ThumbLY > -CONTROLLER_STICK_MAX)
		{
			kanning = 0;
			CntlTime = 0;
		}
	}
	else {
		kanning = 0;
	}
	return kanning;
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
					DrawGraph(StrData[i]->GetStrX()+i%13*13, StrData[i]->GetStrY()+i/13*5+125, StrData[i]->GetBigImage(), TRUE);
				}
				else {
					DrawGraph(StrData[i]->GetStrX() + i%13 * 13, StrData[i]->GetStrY() + i / 13 * 5+125, StrData[i]->GetImage(), TRUE);
				}
			}
			DrawString(360, 20, RememberName,0xffffff);
			DrawFormatString(360, 400, 0xffffff, "%d", kanning);
			
	}
	else {
		for (int i = 0; i < 5; i++) {
			DrawFormatString(200, i * 90, 0xffffff,
				"%d,%s,%d",
				rankdata[i].Rank,
				rankdata[i].Name,
				rankdata[i].Score);

			}
			/*SetFontSize(28);
			DrawString(10, 10, "ランキング表示", 0xFFFFFF);*/
	
	}
	
}


//if (data.ThumbLX == kanning) {
//
//}