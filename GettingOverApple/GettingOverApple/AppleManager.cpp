#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// コンストラクタ
//-----------------------
CAppleManager::CAppleManager()
{
	image = LoadGraph("images/Apple_2.png");

	apple = new CApple(image);

}CAppleManager::~CAppleManager() { delete apple; }

//-------------------------
// 生成
//-------------------------
void CAppleManager::CreateApple()
{	
	//リンゴが非表示なら確保しているメモリを解放し、新たに確保する
	if (apple->GetisShow() == FALSE) {
		delete apple;
		apple = new CApple(image);
	}
}

//------------------------
// 更新
//------------------------
void CAppleManager::Update() {
	//画面外に出たら非表示にする
	if (apple->GetY() >= D_SCREEN_HEIGHT) {
		apple->ToggleisShow();
	}

	//25秒に1回生成を試みる
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) CreateApple();

	//値が入っているリンゴの更新
	if (apple != NULL) {
		apple->Update();
	}
}

//-------------------------
// 描画
//-------------------------
void CAppleManager::Render()const {
	//値が入っているリンゴがあれば描画する
	if (apple != NULL) {
		apple->Render();
	}
}