#pragma once
//�^�C�g���̊Ǘ�
class CTitle :
    public CScene
{
private:
public:
    CTitle(CController* pController) :CScene(pController) {}       //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CTitle() {}

    CScene* Update() override;
    void Render()const override;
};

