#pragma once

class CRanking :
    public CScene
{

private:
public:
    CRanking(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CRanking() {}

    CScene* Update() override;
    void Render()const override;
};