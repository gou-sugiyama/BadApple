#pragma once
#include"define.h"
#define D_WIDTH (195)
#define D_HEIGHT (40)
#define D_MARGIN (40)
#define D_POS_X  D_SCREEN_WIDTH - D_MARGIN - D_WIDTH
#define D_POS_Y (D_SCREEN_HEIGHT - ((D_HEIGHT) * (int)EMenu::D_MARGIN))
#define D_START (0)
#define D_RANKING (1)
#define D_HELP (2)
#define D_END (3)
#define D_MAGNIFICATION 1.2

//�^�C�g���̊Ǘ�
class CTitle :
    public CScene
{
private:
    XINPUT_STATE keyInput;
    int titleImage;
    int startImage;
    int rankingImage;
    int helpImage;
    int endImage;
    int menuCursor;
    int inputInterval;

public:
    CTitle(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CTitle() {}

    CScene* Update() override;
    void SelectMenu();
    void Render()const override;
    void DrawMenu()const;
};

