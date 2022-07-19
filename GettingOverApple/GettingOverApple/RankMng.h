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
    CRankMng(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B

    ~CRankMng();

    CScene* Update();

    bool JudgeRanking() const;      //���͂ƕ\���̔���

    void TrueUpdate();      //����
    bool FalseUpdate();     //�\��

    void ToggleJudge();     //���͂ƕ\���̐؂�ւ�
    void ControlRanking(XINPUT_STATE data);     //�R���g���[���[�̎󂯓n��

    void SetStrImageFlg(int i);     //�����C���[�W�̃Z�b�g
    void SetScore(int i);       //�X�R�A�̃Z�b�g

    void ChangeImage();
    void InsertRankChar(char* data1);       //���O�̏㏑��
    void SortRanking();     //�����L���O�̃\�[�g
    void SaveRanking();

    bool CheckName(char* name);

    int DelayCNTL();        //�R���g���[���[�̃f�B���C

    void Render()const;
};

