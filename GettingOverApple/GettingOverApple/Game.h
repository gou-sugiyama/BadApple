#pragma once
class CPlayer;
class CAppleManager;
class CApple;
class CUI;
class CController;
class CHitBoxCheck;
class CRankMng;

class CGame :
    public CScene
{
private:
    //画像格納用変数
    int image;
    //プレイヤーのポインタ
    CPlayer* player;
    //リンゴを管理するクラスのポインタ
    CAppleManager* appleManager;
    //リンゴを扱うためのポインタ
    CApple* apple;
    //UIを管理するポインタ
    CUI* UI;
    //当たり判定クラス
    CHitBoxCheck* hit;
    //Rank
    CRankMng* rankmng;

    XINPUT_STATE keyInput;
public:
    CGame(CController* pController);

    ~CGame();

    CScene* Update();
    void Render()const;
};

