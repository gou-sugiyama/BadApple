#pragma once
#define D_MENU_WIDTH (195)
#define D_MENU_HEIGHT (40)
#define D_MENU_MARGIN (40)

//�^�C�g���̊Ǘ�
class CTitle :
    public CScene
{
private:
    int titleImage;
    int startImage;
    int rankingImage;
    int helpImage;
    int endImage;
    int menuCursor;

public:
    CTitle(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CTitle() {}

    CScene* Update() override;
    void Render()const override;
};

