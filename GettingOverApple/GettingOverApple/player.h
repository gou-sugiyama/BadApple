#pragma once
#include"Object.h"
#define D_PLAYER_WIDTH (52)
#define D_PLAYER_HEIGHT (100)
#define D_PLAYER_WIDTH_MOVE (80)
#define D_PLAYER_HEIGHT_MOVE (65)
#define D_PLAYER_ADD_SPEED 0.3f
#define D_PLAYER_SUB_SPEED 0.15f
#define D_PLAYER_MAX_SPEED 5.0f//(-5)
#define D_PLAYER_GRAPHIC_NUM (2)
#define D_KEY_CONTROL_LEFT -2000
#define D_KEY_CONTROL_RIGHT 2000
#define D_PLAYER_IMAGE_MAX 2

class CController;

class CPlayer :
	public CObject
{
private:
	//コントローラ
	CController* controller;

	//移動周辺情報
	float speed;

	int direction;
	bool isMove;	//移動しているか？

public:
	CPlayer(CController* pController);
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
	//入力キーの制御
	int KeyControl();

public:
	//当たった時
	void HitAction();
};

