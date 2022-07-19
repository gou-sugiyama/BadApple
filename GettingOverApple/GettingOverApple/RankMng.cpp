#include<stdio.h>
#include"Controller.h"
#include"RankMng.h"
#include"Title.h"
#include<string>

//--------------------------------
// コンストラクタ
//--------------------------------
CRankMng::CRankMng(CController* pController) :CScene(pController) {
#pragma warning(disable:4996)
	//ファイルオープン
	fopen_s(&fp, "dat/rankingdata.txt", "r");

	//ファイルロード
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%1d %9s %10d", &rankdata[i].Rank, rankdata[i].Name, &rankdata[i].Score);
	}
	//ファイルクローズ
	fclose(fp);

	selectSE = LoadSoundMem("sounds/selectSE.wav");
	deleteSE = LoadSoundMem("sounds/deleteSE.wav");

	ChangeVolumeSoundMem(80,selectSE);
	ChangeVolumeSoundMem(80,deleteSE);

	LoadDivGraph("images/FontImage.png", 62, 62, 1, 30, 60, FontImage);
	alldeleteimage = LoadGraph("images/alldelete.png");
	selectimage = LoadGraph("images/select.png");
	spaceimage = LoadGraph("images/space.png");

	for (int i = 0; i < STR_MAX; i++) {
		StrData[i] = new CString(i);
		if (i < 62) {
			StrData[i]->SetFontImage(FontImage[i]);
		}
		else if (i == 62) {
			StrData[i]->SetFontImage(spaceimage);
		}
		else if (i == 63) {
			StrData[i]->SetFontImage(alldeleteimage);
		}
		else if (i == 64) {
			StrData[i]->SetFontImage(selectimage);
		}
	}

	for (int i = 0; i < REMEMBER_STR_MAX; i++) {
		RememberName[i] = '\0';
	}

	backimage = LoadGraph("images/haikei.png");

	WaitTime = 0;
	Type = 0;
	Str = 0;
	Count = 0;

	Score = controller->GetScore();


	JudgeFlg = TRUE;

	controller->ToggleControlFlg();
	ChangeImage();
}

CRankMng::~CRankMng()
{
	delete StrData[STR_MAX - 1];
	SaveRanking();
	controller->SetScore(0);
}



bool CRankMng::JudgeRanking() const
{
	if (rankdata[4].Score < Score) {
		if (JudgeFlg == TRUE) {
			return TRUE;
		}
		else {

			return FALSE;
		}
	}
	else {
		return FALSE;
	}
}

//--------------------------------
// 更新
//--------------------------------
CScene* CRankMng::Update() {
	//controller->control(false);
	if (JudgeRanking() != FALSE) {
		TrueUpdate();
		return this;
	}
	else {
		if (FalseUpdate()) {
			return this;
		}
		else {
			controller->ToggleControlFlg();
			return new CTitle(controller);
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

	if (data.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || Cntller == 1)
	{
		if (0 <= Str % 13 && Str % 13 < 12) {
			Str++;
			FlgCount = 1;
		}
		else if (Str % 13 == 12) {
			Str -= 12;
			FlgCount = 1;
		}

	}
	else {
		FlgCount = 0;
	}
	if (data.Buttons[XINPUT_BUTTON_DPAD_LEFT] || Cntller == 2) {
		if (12 >= Str % 13 && Str % 13 > 0) {
			Str--;
		}
		else if (Str % 13 == 0) {
			Str += 12;
		}
	}
	if (data.Buttons[XINPUT_BUTTON_DPAD_DOWN] || Cntller == 3)
	{
		if (Str + 13 < STR_MAX) {
			Str += 13;
		}
	}
	if (data.Buttons[XINPUT_BUTTON_DPAD_UP] || Cntller == 4)
	{
		if (Str - 13 >= 0) {
			Str -= 13;
		}
	}

	SetStrImageFlg(Str);

	if (0 <= Str && Str < STR_MAX - 2 && data.Buttons[XINPUT_BUTTON_A]) {
		if (Count < 9) {
			if (Str == STR_MAX - 3) {
				RememberName[Count++] = '*';
				NameImage[Count] = 0;
			}
			else {
				RememberName[Count++] = StrData[Str]->GetStr();
				NameImage[Count] = StrData[Str]->GetImage();
			}

			PlaySoundMem(selectSE,DX_PLAYTYPE_BACK,TRUE);
		}
		else {
			Count = 9;
		}
	}

	if (Str == STR_MAX - 2 && data.Buttons[XINPUT_BUTTON_A]) {
		memset(RememberName, '\0', sizeof(RememberName));
		for (int i=0; i <10; i++) {
			NameImage[i] = -1;
		}
		Count = 0;
		PlaySoundMem(deleteSE, DX_PLAYTYPE_BACK, TRUE);

	}

	if (Str == STR_MAX - 1 && data.Buttons[XINPUT_BUTTON_A]) {
		if (CheckName(RememberName)) {
			for (Count; Count < REMEMBER_STR_MAX - 1; Count++) {
				RememberName[Count] = '*';
			}
			RememberName[9] = '\0';

			InsertRankChar(RememberName);
			ToggleJudge();
			PlaySoundMem(selectSE, DX_PLAYTYPE_BACK, TRUE);
		}
		else {

		}

	}

	if (data.Buttons[XINPUT_BUTTON_B]) {
		if (Count > 0) {
			RememberName[Count - 1] = '\0';
			NameImage[Count] = -1;
			Count--;
		}
		else {

		}
		PlaySoundMem(deleteSE, DX_PLAYTYPE_BACK, TRUE);

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

void CRankMng::ChangeImage()
{
	int allnumber;
	int remembernumber[5];

	for (int i = 0; i < 5; i++) {
		allnumber = rankdata[i].Score;
		remembernumber[0] = allnumber / 10000;
		remembernumber[1] = (allnumber - remembernumber[0] * 10000) / 1000;
		remembernumber[2] = (allnumber - remembernumber[0] * 10000 - remembernumber[1] * 1000) / 100;
		remembernumber[3] = (allnumber - remembernumber[0] * 10000 - remembernumber[1] * 1000 - remembernumber[2] * 100) / 10;
		remembernumber[4] = (allnumber - remembernumber[0] * 10000 - remembernumber[1] * 1000 - remembernumber[2] * 100 - remembernumber[3] * 10);

		for (int j = 0; j < STR_MAX; j++) {
			if (rankdata[i].Rank == StrData[j]->GetNumber()) {
				rankdataimg[i].RankImage = StrData[j]->GetImage();
			}
		}
		for (int x = 0; x < 10; x++) {
			for (int j = 0; j < STR_MAX; j++) {
				if (rankdata[i].Name[x] == StrData[j]->GetStr()) {
					rankdataimg[i].NameImge[x] = StrData[j]->GetImage();
				}
				else if (rankdata[i].Name[x] == '*'){
					rankdataimg[i].NameImge[x] = 0;
				}
			}
		}
		for (int x = 0; x < 5; x++) {
			for (int j = 0; j < STR_MAX; j++) {
				if (remembernumber[x] == StrData[j]->GetNumber()) {
					rankdataimg[i].ScoreImage[x] = StrData[j]->GetImage();
				}
			}

		}
	}
}

void CRankMng::InsertRankChar(char* data1)
{

	memset(rankdata[4].Name, '\0', sizeof(rankdata[4].Name));

	strcpy(rankdata[4].Name, data1);
	rankdata[4].Score = this->Score;

	SortRanking();
	ChangeImage();
}

void CRankMng::SortRanking()
{
	int work;
	char SaveStorage[10];
	// 選択法ソート
	for (int i = 3; i >= 0; i--) {
		for (int j = i + 1; j > 0; j--) {
			if (rankdata[i].Score <= rankdata[j].Score) {
				work = rankdata[i].Score;
				strcpy(SaveStorage, rankdata[i].Name);
				rankdata[i].Score = rankdata[j].Score;
				memset(rankdata[i].Name, '\0', sizeof(rankdata[i].Name));
				strcpy(rankdata[i].Name, rankdata[j].Name);
				rankdata[j].Score = work;
				memset(rankdata[j].Name, '\0', sizeof(rankdata[j].Name));
				strcpy(rankdata[j].Name, SaveStorage);
			}
		}
	}

	// 順位付け
	for (int i = 0; i < 4; i++) {
		rankdata[i].Rank = i + 1;
	}
}

void CRankMng::SaveRanking()
{
#pragma warning(disable:4996)
	fopen_s(&fp, "dat/rankingdata.txt", "w");

	//ファイルロード
	for (int i = 0; i < 5; i++) {
		fprintf(fp, "%1d %9s %10d\n", rankdata[i].Rank, rankdata[i].Name, rankdata[i].Score);
	}
	//ファイルクローズ
	fclose(fp);
}

bool CRankMng::CheckName(char* name)
{
	for (int i = 0; i < REMEMBER_STR_MAX; i++) {
		if (name[i] != '*' && name[i] != '\0') {
			return TRUE;
			break;
		}
	}
	return false;
}

int CRankMng::DelayCNTL()
{
	if (CntlTime++ % 30 == 0) {
		if (data.ThumbLX > CONTROLLER_STICK_MAX) {
			stick = 1;
		}
		if (data.ThumbLX < -CONTROLLER_STICK_MAX - 1) {
			stick = 2;
		}
		if (data.ThumbLY < -CONTROLLER_STICK_MAX - 1) {
			stick = 3;
		}
		if (data.ThumbLY > CONTROLLER_STICK_MAX) {
			stick = 4;
		}
		if (data.ThumbLX < CONTROLLER_STICK_MAX && data.ThumbLX > -CONTROLLER_STICK_MAX
			&& data.ThumbLY < CONTROLLER_STICK_MAX && data.ThumbLY > -CONTROLLER_STICK_MAX)
		{
			stick = 0;
			CntlTime = 0;
		}
	}
	else {
		stick = 0;
	}
	return stick;
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
void CRankMng::Render() const {

	DrawGraph(0, 0, backimage, FALSE);

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 50);
	DrawBox(0, 0, D_SCREEN_WIDTH, D_SCREEN_HEIGHT, 0x0f00f5, TRUE);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);

	if (JudgeRanking() != FALSE) {


		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 50);
		DrawBox(300, 30, 600, 90, 0xff00ff, TRUE);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
		for (int i = 0; i < STR_MAX; i++) {
			if (StrData[i]->GetStrFlg() == TRUE) {
				DrawRotaGraph2(StrData[i]->GetStrX() + i % 13 * 13, StrData[i]->GetStrY() + i / 13 * 5 + 125
					, 30 / 2, 60 / 2, 1.2, 0, StrData[i]->GetImage(), TRUE);
			}
			else {
				DrawRotaGraph2(StrData[i]->GetStrX() + i % 13 * 13, StrData[i]->GetStrY() + i / 13 * 5 + 125
					, 30 / 2, 60 / 2, 1, 0, StrData[i]->GetImage(), TRUE);
			}
		}
		//DrawString(360, 20, RememberName,0xffffff);

		for (int i = 0; i < 10; i++) {
			DrawRotaGraph2(300 + i * 30, 60
				, 30 / 2, 60 / 2, 1, 0, NameImage[i], TRUE);
		}
	}
	else {




		for (int i = 0; i < 5; i++) {
			/*	DrawFormatString(200, i * 90, 0xffffff,
					"%d,%s,%d",
					rankdata[i].Rank,
					rankdata[i].Name,
					rankdata[i].Score);*/



			DrawRotaGraph2(50, i * 60 + 50
				, 30 / 2, 60 / 2, 1, 0, rankdataimg[i].RankImage, TRUE);

			for (int j = 0; j < 10; j++) {
				DrawRotaGraph2(150 + j * 30, i * 60 + 50
					, 30 / 2, 60 / 2, 1, 0, rankdataimg[i].NameImge[j], TRUE);
			}
			for (int j = 0; j < 5; j++) {
				DrawRotaGraph2(450 + j * 30, i * 60 + 50
					, 30 / 2, 60 / 2, 1, 0, rankdataimg[i].ScoreImage[j], TRUE);
			}

		}
		/*SetFontSize(28);
		DrawString(10, 10, "ランキング表示", 0xFFFFFF);*/

	}
}