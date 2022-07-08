#pragma once
#include"define.h"
#define D_WIDTH (195)
#define D_HEIGHT (50)   //menu�摜�T�C�Y + margin10
#define D_MARGIN (40)
#define D_START (0)
#define D_RANKING (1)
#define D_HELP (2)
#define D_END (3)
#define D_POS_X  D_SCREEN_WIDTH - D_MARGIN - D_WIDTH / 2
#define D_POS_Y (D_SCREEN_HEIGHT - (D_HEIGHT * (D_END + 2)) + (int)(D_HEIGHT / 2))
#define D_ENLARGEMENT 1.2
#define D_KEY_CONTROL_UP 2000
#define D_KEY_CONTROL_DOWN -2000
#define D_INPUT_INTERVAL 20


//�^�C�g���̊Ǘ�
class CTitle :
    public CScene
{
private:
    XINPUT_STATE keyInput;
    int titleImage;
    int menuImage[4];
    int menuCursor;

public:
    CTitle(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CTitle() {}

    CScene* Update() override;
    void SelectMenu();
    int KeyControl();
    void Render()const override;
    void DrawMenu()const;
};
