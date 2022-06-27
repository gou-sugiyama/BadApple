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
	int g_player;//プレイヤー画像変数
	int g_playerx;//座標x
	int	g_playery;//座標y
	int g_playerw;//高さ
	int g_playerh;//幅
	int g_playerflg;//フラグ
	int g_playercount;//カウント
	float speed;//スピード
	int i;//秒数
	
};