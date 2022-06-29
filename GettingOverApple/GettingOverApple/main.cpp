#include "DxLib.h"
#include"SceneManager.h"
#include"Controller.h"
#include"Title.h"
#include"Game.h"//TODO:消す
#include"Apple.h"
#include"UI.h"
/*************************************************************************
*	変数の宣言
**************************************************************************/

int g_OldKey;	//前回の入力キー
int g_NowKey;	//今回の入力キー
int g_KeyFlg;	//入力キー情報



/*************************************************************************
*	プログラムの開始
**************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpcmdLine, int nCmdShow) {
	SetMainWindowText("GettingOverApple");

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	//コントローラの動的確保
	CController* controller;
	controller = new CController;

	//管理システムを動的確保
	CSceneManager* manager;
	manager = new CSceneManager(new CGame(controller));

	//ゲームループ
	while (ProcessMessage() == 0 
		&& manager->Update() != nullptr&& (controller->control(true)).Buttons[5] != TRUE) {
		//入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		//画面の初期化

		manager->Render();

		ScreenFlip();				//裏画面の内容を表画面に反映
	}

	//managerの解放
	delete manager;
	//controllerの解放
	delete controller;


	DxLib_End();					//DXライブラリ使用の終了処理
	return 0;				//ソフト終了
}
