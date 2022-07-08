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



    void InitRank(int i);

public:
    CRankMng(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。

    ~CRankMng() {}

    bool  JudgeRanking() const;
  

    CScene* Update();

    void TrueUpdate();

    void InsertRanking();


    void FalseUpdate();

    void Render() const;


};

