#pragma once
class CController;
class CPlayer {
public:
	CPlayer(CController* pController);
	void Update();
	void Render()const;
	void playerspeed();
	int KeyControl();
	int GetPlayerX() { return g_playerx; };
	int GetPlayerY() { return g_playery; };
	int GetPlayerW() { return g_playerw; };
	int GetPlayerH() { return g_playerh; };
private:
	CController* controller;
	int g_player;//�v���C���[�摜�ϐ�
	float g_playerx;//���Wx
	int	g_playery;//���Wy
	int g_playerw;//����
	int g_playerh;//��
	int g_playerflg;//�t���O
	int g_playercount;//�J�E���g
	float speed;//�X�s�[�h
	int i;//�b��
	
};