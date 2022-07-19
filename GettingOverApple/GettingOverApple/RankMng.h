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
#define STR_NUMBER_LOWSTR 26
#define STR_NUMBER_NUM 52
#define REMEMBER_STR_MAX 10

class CString
{
private:
    int str_X;
    int str_Y;
    int image;
    char string;
    bool strflg;
    int Number;

public:

    CString(int i);

    bool GetStrFlg() { return strflg; }
    void SetStrFlg(bool i) { strflg = i; }
    int GetStrX() { return str_X; }
    int GetStrY() { return str_Y; }
    int GetImage() { return image; }
    char GetStr() { return string; }
    void SetFontImage(int i) {image = i;}
    int GetNumber() { return Number; }
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
        char Name[10];
        int Score;
    };

    struct RankingData rankdata[5];

    typedef struct RankingDataImage {
        int RankImage;
        int NameImge[10];
        int ScoreImage[5];
    };
    struct RankingDataImage rankdataimg[5];

    int FontImage[STR_MAX - 3];

    int stick;
    int FlgCount;


    int backimage;
    int alldeleteimage;
    int selectimage;
    int spaceimage;

    int selectSE;
    int deleteSE;

    int WaitTime;
    int CntlTime;
    int Score;

    int Type;
    int Str;
    int Count;

    bool JudgeFlg;

    char RememberName[10];
    int NameImage[10];

public:
    CRankMng(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。

    ~CRankMng();

    CScene* Update();

    bool JudgeRanking() const;      //入力と表示の判定

    void TrueUpdate();      //入力
    bool FalseUpdate();     //表示

    void ToggleJudge();     //入力と表示の切り替え
    void ControlRanking(XINPUT_STATE data);     //コントローラーの受け渡し

    void SetStrImageFlg(int i);     //文字イメージのセット
    void SetScore(int i);       //スコアのセット

    void ChangeImage();
    void InsertRankChar(char* data1);       //名前の上書き
    void SortRanking();     //ランキングのソート
    void SaveRanking();

    bool CheckName(char* name);

    int DelayCNTL();        //コントローラーのディレイ

    void Render()const;
};

