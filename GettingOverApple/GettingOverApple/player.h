#pragma once
class player {
public:
	void PlayerControl();
	void GameInit();
	int LoadImages();
	void Draw();
	void playerspeed();
private:
	int g_player;//�v���C���[�摜�ϐ�
	int g_playerx;//���Wx
	int	g_playery;//���Wy
	int g_playerw;//����
	int g_playerh;//��
	int g_playerflg;//�t���O
	int g_playercount;//�J�E���g
	int g_Nowkey;//���̃L�[
	int g_KeyFlg;//���̓L�[���
	int g_OldKey;//�O�̃L�[
	int speed;
	int i;
	
};