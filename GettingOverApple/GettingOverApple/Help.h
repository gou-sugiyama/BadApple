#pragma once
class CHelp :
    public CScene
{
private:
    int image;
    int HelpBGM;
public:
    CHelp(CController* pController);      //���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
    ~CHelp() {}

    CScene* Update() override;
    void Render()const override;
};