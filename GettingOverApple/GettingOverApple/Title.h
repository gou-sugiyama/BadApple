#pragma once
//�^�C�g���̊Ǘ�
class CTitle :
    public CScene
{
private:
public:
    CTitle(CController* pController) ;
    ~CTitle() {}

    CScene* Update() override;
    void Render()const override;
};

