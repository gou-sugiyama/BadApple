#pragma once
#pragma warning(disable:4996)
#define STR_MAX 28
#define STR_TYPE 3


class CRanking;
class CUI;

class CRankMng:
    public CScene
{
private:
    CRanking* rankdata[5];
    CUI* ui;
    FILE* fp;

    int WaitTime;
    int Score;

    int Type;
    int Str;
    int Count;

    bool JudgeFlg;

    struct RankString
    {
        int str_X;
        int str_Y;
        int image;
        int bigimage;
        char string;
        bool strflg;
    };
    RankString rankstr[STR_TYPE][STR_MAX];

    struct RankCursor
    {
        int crsr_X;
        int crsr_Y;
    };
    RankCursor  rankcrsr[STR_TYPE][STR_MAX];

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

    void ToggleStrFlg(int i,int j);
    void SetScore(int i);

    void Render();


};

