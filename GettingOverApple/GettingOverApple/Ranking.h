#pragma once
#pragma warning(disable:4996)

class CRanking;
class CUI;

class CRankMane:
    public CScene
{
private:
    CRanking* rankdata[5];
    CUI* ui;
    FILE* fp;

    void InitRank(int i);

public:
    CRankMane(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CRankMane() {}

    bool  JudgeRanking(int i);
  

    CScene* Update();
    void Render() const;


};

