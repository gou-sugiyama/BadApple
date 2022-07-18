#pragma once
class CController;
class CPlayer {
public:
	CPlayer(CController* pController);
	void Update();
	void Render();
	void playerspeed();
	void HitAction();
	int KeyControl();
	int GetPlayerX() { return g_playerx; };
	int GetPlayerY() { return g_playery; };
	int GetPlayerW() { return g_playerw; };
	int GetPlayerH() { return g_playerh; };
	int GetTnos()const { return tnos; }
private:
	CController* controller;
	int g_player;//�v���C���[�摜�ϐ�
	int g_playerRun;
	float g_playerx;//���Wx
	float g_playery;//���Wy
	int g_playerw;//����
	int g_playerh;//��
	bool g_playerflg;//�t���O
	int angle;//����
	int tnos;//�_�ŕb��
	float mv;//�����x
	float cmx;//�ړ���
	float fcos[180];
	float bk;//�_�Ńt���[��
};