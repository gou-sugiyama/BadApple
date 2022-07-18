#pragma once
class CPlayer;
class CAppleManager;
class CUI;
class CController;
class CHitBoxCheck;
class CApple;

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
    //アップルを呼び出すためのポインタ
    CApple* apple;
    //画僧変数
    int image;

public:
    CGame(CController* pController);
    ~CGame();

    CScene* Update()override;
    void Render()const override;

private:
    void HitAction(CApple* apple,CPlayer*player);
};

