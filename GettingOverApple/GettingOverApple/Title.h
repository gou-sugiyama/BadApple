#pragma once
//�^�C�g���̊Ǘ�

class CTitle :
    public CScene
{
public:
    CTitle(CManager* pManager) :CScene(pManager) {};        //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CTitle() {};

    void Update() override;
    void Render() override;
};

