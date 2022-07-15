#pragma once

#include"DxLib.h"
#include"SceneManager.h"
#include"UI.h"


#include<string>
using namespace std;

#pragma warning(disable:4996)
#define STR_MAX 65
#define STR_TYPE 3
#define CONTROLLER_STICK_MAX 20000

class CString
{
private:
    int str_X;
    int str_Y;
    int image;
    int bigimage;
    char string;
    bool strflg;

public:

    CString(int i);

    bool GetStrFlg() { return strflg; }
    void SetStrFlg(bool i) { strflg = i; }
    int GetStrX() { return str_X; }
    int GetStrY() { return str_Y; }
    int GetImage() { return image; }
    int GetBigImage() { return bigimage; }
    char GetStr() { return string; }

};

class CRankMng:
    public CScene
{
private:
    CString* StrData[STR_MAX];
    CUI* ui;
    FILE* fp;

    XINPUT_STATE data;

    typedef struct RankingData {
        int Rank;
        char Name[9];
        int Score;
    };

    struct RankingData rankdata[5];


    int kanning;
    int FlgCount;


    int WaitTime;
    int CntlTime;
    int Score;

    int Type;
    int Str;
    int Count;

    bool JudgeFlg;

    char RememberName[9];

public:
    CRankMng(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。

    ~CRankMng();

    CScene* Update();

    int JudgeRanking() const;

    void TrueUpdate();
    bool FalseUpdate();

    void ToggleJudge();
    void ControlRanking(XINPUT_STATE data);

    void SetStrImageFlg(int i);
    void SetScore(int i);

    void InsertRankChar(char* data1);
    void SortRanking();

    int DelayCNTL();

    void Render()const;
};

