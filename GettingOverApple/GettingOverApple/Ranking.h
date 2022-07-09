#pragma once
#pragma warning(disable:4996)

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
    
    struct RankString
    {
        int str_X;
        int str_Y;
        int image;
    };
    RankString rankstr[3][26];

public:
    CRankMng(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。

    ~CRankMng() { delete []rankdata; }


    CScene* Update();

    bool  JudgeRanking() const;

    void TrueUpdate();
    bool FalseUpdate();

    void InsertRanking();

    void Render() const;


};

