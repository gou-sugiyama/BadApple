#pragma once
class CPlayer;
class CGame :
    public CScene
{
private:
    //�v���C���[�̃|�C���^
    CPlayer* player;
public:
    CGame(CManager* pManager);

    ~CGame();

    void Update();
    void Render();
};

