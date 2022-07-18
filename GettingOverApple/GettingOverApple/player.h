#pragma once
#include"Object.h"
#define D_PLAYER_WIDTH (52)
#define D_PLAYER_HEIGHT (100)
#define D_PLAYER_WIDTH_MOVE (80)
#define D_PLAYER_HEIGHT_MOVE (65)
#define D_PLAYER_ADD_SPEED 0.3f
#define D_PLAYER_SUB_SPEED 0.15f
#define D_PLAYER_MAX_SPEED 5.0f//(-5)
#define D_PLAYER_GRAPHIC_NUM (2)
#define D_KEY_CONTROL_LEFT -2000
#define D_KEY_CONTROL_RIGHT 2000
#define D_PLAYER_IMAGE_MAX 2

class CController;

class CPlayer :
	public CObject
{
private:
	//�R���g���[��
	CController* controller;

	//�ړ����ӏ��
	float speed;

	int direction;
	bool isMove;	//�ړ����Ă��邩�H

public:
	CPlayer(CController* pController);
	~CPlayer();

	//�X�V
	void Update();
	//�`��
	void Render()const;

private:
	//�X�s�[�h�̉��Z
	void AddSpeed();
	//�X�s�[�h�̐���
	void SpeedControl();
	//�����蔻��̍X�V
	void SetWH();
	//���̓L�[�̐���
	int KeyControl();

public:
	//����������
	void HitAction();
};

