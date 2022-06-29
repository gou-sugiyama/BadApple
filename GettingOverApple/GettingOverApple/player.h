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
	int g_player;//プレイヤー画像変数
	float g_playerx;//座標x
	int	g_playery;//座標y
	int g_playerw;//高さ
	int g_playerh;//幅
	int g_playerflg;//フラグ
	int g_playercount;//カウント
	float speed;//スピード
	int i;//秒数
	
};