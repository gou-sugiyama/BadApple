#pragma once
class CRankMng;


class CRanking
{
private:
    XINPUT_STATE input;

    int Rank = 0;
    char* Name[9];
    int Score = 0;

public:
    CRanking(int data1,char* data2,int data3);

    int ShowRankScore() const { return Score; }

    void InsertRankChar(char* data);

    void Update();

    void Render() const;
};

