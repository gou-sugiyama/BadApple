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
    //プレイヤーのポインタ
    CPlayer* player;
    //リンゴを管理するクラスのポインタ
    CAppleManager* applemanager;
    //UIを管理するポインタ
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

