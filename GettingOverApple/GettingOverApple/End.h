#pragma once
#include "SceneManager.h"
class CEnd :
    public CScene
{
private:
    int image;
public:
    CEnd(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CEnd() {}

    CScene* Update() override;
    void Render()const override;
};
