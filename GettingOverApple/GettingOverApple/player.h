#pragma once
#define D_PLAYER_WIDTH (40)
#define D_PLAYER_HEIGHT (100)
#define D_PLAYER_WIDTH_MOVE (60)
#define D_PLAYER_HEIGHT_MOVE (80)
#define D_PLAYER_ADD_SPEED 0.3f
#define D_PLAYER_SUB_SPEED 0.15f
#define D_PLAYER_MAX_SPEED 5.0f//(-5)
#define D_PLAYER_GRAPHIC_NUM (2)
#define D_KEY_CONTROL_LEFT -2000
#define D_KEY_CONTROL_RIGHT 2000

class CController;

class CPlayer
{
private:
	//�R���g���[��
	CController* controller;

	//�摜�f�[�^�i�[
	int graphic[D_PLAYER_GRAPHIC_NUM];

	//���W���ӏ��
	int width;
	int height;
	float x;
	float y;

	//�ړ����ӏ��
	float speed;
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
};

