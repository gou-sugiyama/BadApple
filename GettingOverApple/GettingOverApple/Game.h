#pragma once
class CPlayer;
class CAppleManager;
class CUI;
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
public:
    CGame(CSceneManager* pManager);

    ~CGame();

    CScene* Update();
    void Render()const;
};

