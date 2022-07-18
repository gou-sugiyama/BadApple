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
	int g_player;//プレイヤー画像変数
	int g_playerRun;
	float g_playerx;//座標x
	float g_playery;//座標y
	int g_playerw;//高さ
	int g_playerh;//幅
	bool g_playerflg;//フラグ
	int angle;//方向
	int tnos;//点滅秒数
	float mv;//加速度
	float cmx;//移動量
	float fcos[180];
	float bk;//点滅フレーム
};