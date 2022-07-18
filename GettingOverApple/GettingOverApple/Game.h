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
    //�v���C���[�̃|�C���^
    CPlayer* player;
    //�����S���Ǘ�����N���X�̃|�C���^
    CAppleManager* applemanager;
    //UI���Ǘ�����|�C���^
    CUI* UI;
    //�A�b�v�����Ăяo�����߂̃|�C���^
    CApple* apple;
    //��m�ϐ�
    int image;

public:
    CGame(CController* pController);
    ~CGame();

    CScene* Update()override;
    void Render()const override;

private:
    void HitAction(CApple* apple,CPlayer*player);
};

