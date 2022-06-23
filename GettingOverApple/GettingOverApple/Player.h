#pragma once
#define D_PLAYER_WIDTH (40)
#define D_PLAYER_HEIGHT (100)
#define D_PLAYER_WIDTH_MOVE (60)
#define D_PLAYER_HEIGHT_MOVE (80)
#define D_PLAYER_ADD_SPEED 0.3f
#define D_PLAYER_SUB_SPEED 0.15f
#define D_PLAYER_MAX_SPEED 5.0f//(-5)
#define D_PLAYER_GRAPHIC_NUM (2)
class CManager;
class CPlayer
{
private:
	//シーン管理クラス
	CManager* manager;		//入力をもらいたい

	//画像データ格納
	int graphic[D_PLAYER_GRAPHIC_NUM];

	//DXライブラリで定義されている構造体(中身はfloat型のx,y,z)
	int width;
	int height;
	float x;
	float y;

	float speed;
	bool isMove;

public:
	CPlayer(CManager*);
	~CPlayer();

	//更新
	void Update();
	//描画
	void Render();

private:
	//スピードの加算
	void AddSpeed();
	//スピードの制御
	void SpeedControl();
	//当たり判定の更新
	void SetWH();
};

