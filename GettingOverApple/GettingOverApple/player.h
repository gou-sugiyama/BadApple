#pragma once
class player {
public:
	void PlayerControl();
	void GameInit();
	int LoadImages();
	void Draw();
	void playerspeed();
private:
	int g_player;//プレイヤー画像変数
	int g_playerx;//座標x
	int	g_playery;//座標y
	int g_playerw;//高さ
	int g_playerh;//幅
	int g_playerflg;//フラグ
	int g_playercount;//カウント
	int g_Nowkey;//今のキー
	int g_KeyFlg;//入力キー情報
	int g_OldKey;//前のキー
	int speed;
	int i;
	
};