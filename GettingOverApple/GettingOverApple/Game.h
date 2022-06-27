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
    CGame(CSceneManager* pManager);

    ~CGame();

    CScene* Update();
    void Render()const;
};

