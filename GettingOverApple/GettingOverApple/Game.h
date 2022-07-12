#pragma once
class CPlayer;
class CAppleManager;
class CUI;
class CController;
class CHitBoxCheck;
class CRankMng;

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
    //Hit
    CHitBoxCheck* hit;
    //Rank
    CRankMng* rankmng;

public:
    CGame(CController* pController);

    ~CGame();

    CScene* Update();
    void Render()const;
};

