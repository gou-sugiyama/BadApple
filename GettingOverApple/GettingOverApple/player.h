#pragma once
class CSceneManager;
class CPlayer {
public:
	CSceneManager* manager;
	CPlayer(CSceneManager* pManager);
	void Render()const;
	void playerspeed();
	void Update();

private:
	int g_player;//�v���C���[�摜�ϐ�
	int g_playerx;//���Wx
	int	g_playery;//���Wy
	int g_playerw;//����
	int g_playerh;//��
	int g_playerflg;//�t���O
	int g_playercount;//�J�E���g
	float speed;//�X�s�[�h
	int i;//�b��
	
};