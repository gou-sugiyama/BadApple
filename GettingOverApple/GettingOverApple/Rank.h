#pragma once
class CRankMane;
class CRanking
{
private:

    int Rank = 0;
    char Name[9];
    int Score = 0;

public:
    CRanking(int i);

    int ShowRankDeta(int i) const { return rankdeta[i].Score; }
    void InsertRanking(int i);


    void Update();
    void Render() const;
};

