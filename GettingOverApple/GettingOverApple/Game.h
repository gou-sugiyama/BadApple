#pragma once
class CPlayer;
class CAppleManager;
class CGame :
    public CScene
{
private:
    //プレイヤーのポインタ
    CPlayer* player;
    //リンゴを管理するクラスのポインタ
    CAppleManager* applemanager;
public:
    CGame(CManager* pManager);

    ~CGame();

    void Update();
    void Render();
};

