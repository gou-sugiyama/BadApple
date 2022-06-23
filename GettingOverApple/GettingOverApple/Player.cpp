#include"DxLib.h"
#include"Player.h"
#include"Manager.h"
#include"define.h"

CPlayer::CPlayer(CManager* pManager) {
	//CManagerのアドレス格納
	manager = pManager;
	//画像データ
	graphic[false] = LoadGraph("images/car1.bmp");
	graphic[true] = LoadGraph("images/car1pol.bmp");
	//画像情報初期化
	width = D_PLAYER_WIDTH;
	height = D_PLAYER_HEIGHT;

	//位置を初期化(座標は x:ゲーム領域の中心, y:ウインドウの下辺)
	x = (float)(D_GAME_AREA / 2);
	y = (float)(D_SCREEN_HEIGHT - (height / 2));	//RotaGraphで描画するため画像サイズの2分の一にする

	speed = 0;
	isMove = false;
}

CPlayer::~CPlayer() {

}

void CPlayer::Update() {
	//スピードの加算
	AddSpeed();

	//移動中なら当たり判定を変える
	SetWH();

	//speedの最大値、最小値、原点の制御
	SpeedControl();

	x += speed;
	//ゲーム領域の端で止める
	if (x < D_PLAYER_WIDTH_MOVE) x = D_PLAYER_WIDTH_MOVE;		//左端
	if (x > D_GAME_AREA - D_PLAYER_WIDTH_MOVE)x = D_GAME_AREA - D_PLAYER_WIDTH_MOVE;		//左端
}

void CPlayer::Render() {
	DrawRotaGraph((int)x, (int)y, 1.0f, 0, graphic[isMove], FALSE);

	DrawFormatString(0, 20, 0xFFFFFF, "%lf", this->x);
	DrawFormatString(0, 40, 0xFFFFFF, "%lf", this->speed);
	DrawFormatString(0, 60, 0xFFFFFF, "%d", this->width);
	DrawFormatString(0, 80, 0xFFFFFF, "%d", this->height);
}

void CPlayer::AddSpeed() {
	//キー入力中にspeedに加算
	if (*(manager->GetKey()) & PAD_INPUT_LEFT) {
		speed -= D_PLAYER_ADD_SPEED;
		isMove = true;
	}
	if (*(manager->GetKey()) & PAD_INPUT_RIGHT) {
		speed += D_PLAYER_ADD_SPEED;
		isMove = true;
	}
}

void CPlayer::SpeedControl() {
	//最大値、最小値の制御
	if (speed < -D_PLAYER_MAX_SPEED)speed = -D_PLAYER_MAX_SPEED;
	if (speed > D_PLAYER_MAX_SPEED)speed = D_PLAYER_MAX_SPEED;

	//毎フレームspeedを0に少しずつ近づけ、0になったら移動フラグをfalseする
	if (speed > 0) {
		speed -= D_PLAYER_SUB_SPEED;
		if (speed < 0) {
			speed = 0;
		}
	}
	if (speed < 0) {
		speed += D_PLAYER_SUB_SPEED;
		if (speed > 0) {
			speed = 0;
		}
	}
	if (speed == 0) isMove = false;
}

void CPlayer::SetWH() {
	//移動中
	if (isMove) {
		width = D_PLAYER_WIDTH_MOVE;
		height = D_PLAYER_HEIGHT_MOVE;
	}
	//待機中
	else {
		width = D_PLAYER_WIDTH;
		height = D_PLAYER_HEIGHT;
	}
}