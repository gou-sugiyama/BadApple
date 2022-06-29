#pragma once
class CPlayer;
class CAppleManager;
class CUI;
class CController;
class CHitBoxCheck;

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

public:
    CGame(CController* pController);

    ~CGame();

    CScene* Update();
    void Render()const;
};

