#pragma once
#define D_PLAYER_WIDTH (40)
#define D_Player2.hEIGHT (100)
#define D_PLAYER_WIDTH_MOVE (60)
#define D_Player2.hEIGHT_MOVE (80)
#define D_PLAYER_ADD_SPEED 0.3f
#define D_PLAYER_SUB_SPEED 0.15f
#define D_PLAYER_MAX_SPEED 5.0f//(-5)
#define D_PLAYER_GRAPHIC_NUM (2)
class CSceneManager;
class CPlayer
{
private:
	//シーン管理クラス
	CSceneManager* manager;		//入力をもらいたい

	//画像データ格納
	int graphic[D_PLAYER_GRAPHIC_NUM];

	//座標周辺情報
	int width;
	int height;
	float x;
	float y;

	//移動周辺情報
	float speed;
	bool isMove;	//移動しているか？

public:
	CPlayer(CSceneManager*);
	~CPlayer();

	//更新
	void Update();
	//描画
	void Render()const;

private:
	//スピードの加算
	void AddSpeed();
	//スピードの制御
	void SpeedControl();
	//当たり判定の更新
	void SetWH();
};

