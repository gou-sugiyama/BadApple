#pragma once
//�^�C�g���̊Ǘ�

class CTitle :
    public CScene
{
private:
    CController* Controller;
public:
    CTitle(CController* pController) :CScene(pController) {}        //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CTitle() { delete Controller; }

    CScene* Update() override;
    void Render()const override;
};

