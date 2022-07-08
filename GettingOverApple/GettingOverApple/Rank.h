#pragma once
class CRankMng;


class CRanking
{
private:
    XINPUT_STATE input;

    int Rank = 0;
    char Name[9];
    int Score = 0;

public:
    CRanking(FILE* fp);

    int ShowRankDeta() const { return Score; }



    void Update();

    void Render() const;
};

