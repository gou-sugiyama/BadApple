#pragma once
#pragma warning(disable:4996)
#define STR_MAX 65
#define STR_TYPE 3

class CString;
class CRanking;
class CUI;

class CRankMng:
    public CScene
{
private:
    CRanking* rankdata[5];
    CString* StrData[STR_MAX];
    CUI* ui;
    FILE* fp;

    int WaitTime;
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

    bool InsertJudge() const;
    void ToggleJudge();
    void InsertRanking(XINPUT_STATE data,int i);

    void ToggleStrFlg(int i);
    void SetScore(int i);

    void Render()const;


};

