#pragma once
class CPlayer;
class CGame :
    public CScene
{
private:
    //プレイヤーのポインタ
    CPlayer* player;
public:
    CGame(CManager* pManager);

    ~CGame();

    void Update();
    void Render();
};

