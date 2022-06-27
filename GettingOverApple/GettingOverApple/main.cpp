#include "DxLib.h"
#include"SceneManager.h"
#include"Title.h"
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


	//管理システムを動的確保
	CSceneManager* manager;
	manager = new CSceneManager(&g_NowKey);

	//タイトルを動的確保
	manager->scene = new CTitle(manager);

	//ゲームループ
	while (ProcessMessage() == 0 && !(g_KeyFlg & PAD_INPUT_START) && manager->Update() != nullptr) {
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

	DxLib_End();					//DXライブラリ使用の終了処理
	return 0;				//ソフト終了
}
