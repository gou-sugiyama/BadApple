#pragma once
class player {
public:
	void PlayerControl();
	void GameInit();
	int LoadImages();
	void Draw();
	void playerspeed(int g_Nowkey, int g_OldKey);
	void UpdateX(int g_Nowkey);

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