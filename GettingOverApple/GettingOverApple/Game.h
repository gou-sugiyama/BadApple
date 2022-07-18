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
    //�摜�i�[�p�ϐ�
    int image;
    //�v���C���[�̃|�C���^
    CPlayer* player;
    //�����S���Ǘ�����N���X�̃|�C���^
    CAppleManager* appleManager;
    //�����S���������߂̃|�C���^
    CApple* apple;
    //UI���Ǘ�����|�C���^
    CUI* UI;
    //�����蔻��N���X
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

