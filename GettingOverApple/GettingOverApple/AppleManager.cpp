#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// コンストラクタ
//-----------------------
CAppleManager::CAppleManager()
{
	apple = new CApple[D_APPLE_MAX];
	CreateApple();
	CreateApple();
	CreateApple();
	CreateApple();
}
CAppleManager::~CAppleManager() { delete[] apple; }

//-------------------------
// 生成
//-------------------------
void CAppleManager::CreateApple()
{	
	//リンゴが非表示ならりんごを初期化する
	for (int i = 0; i < D_APPLE_MAX; i++) {
		if (apple[i].GetisShow() == false) {
			apple[i].NewApple();
			break;
		}
	}
	
}

//------------------------
// 更新
//------------------------
void CAppleManager::Update() {

	//25フレームに1回生成を試みる
	static int WaitTime = 0;
	if (!(++WaitTime % 25))CreateApple();

	//見えているリンゴの更新
	for (int i = 0; i < D_APPLE_MAX; i++) {

		if (apple[i].GetisShow() == true) {
			apple[i].Update();
		}
		//画面外に出たら非表示にする
		if (apple[i].GetY() >= D_SCREEN_HEIGHT && apple[i].GetisShow()) {
			apple[i].ToggleisShow();
		}
	}
}
//-------------------------
// 描画
//-------------------------
void CAppleManager::Render()const {
	//見えているリンゴの描画
	for (int i = 0; i < D_APPLE_MAX; i++) {

		if (apple[i].GetisShow() == true) {
			apple[i].Render();
		}
		DrawFormatString(0, 100 + 20 * i, 0xFFFFFF, 
			"apple[%d]:%d   y:%.0f x:%.0f", i, (int)apple[i].GetisShow(),apple[i].GetY(),apple[i].GetX());
	}
}