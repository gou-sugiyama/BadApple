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
    CGame(CSceneManager* pManager);

    ~CGame();

    CScene* Update();
    void Render()const;
};

