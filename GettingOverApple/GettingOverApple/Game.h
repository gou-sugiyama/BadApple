#pragma once
class CPlayer;
class CAppleManager;
class CUI;
class CGame :
    public CScene
{
private:
    //�v���C���[�̃|�C���^
    CPlayer* player;
    //�����S���Ǘ�����N���X�̃|�C���^
    CAppleManager* applemanager;
    //UI���Ǘ�����|�C���^
    CUI* UI;
public:
    CGame(CSceneManager* pManager);

    ~CGame();

    CScene* Update();
    void Render()const;
};

