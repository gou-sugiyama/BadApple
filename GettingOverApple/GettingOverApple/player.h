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