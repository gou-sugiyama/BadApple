#pragma once
class CPlayer;
class CAppleManager;
class CGame :
    public CScene
{
private:
    //�v���C���[�̃|�C���^
    CPlayer* player;
    //�����S���Ǘ�����N���X�̃|�C���^
    CAppleManager* applemanager;
public:
    CGame(CManager* pManager);

    ~CGame();

    void Update();
    void Render();
};

