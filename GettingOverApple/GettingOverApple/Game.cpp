#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"Player2.h"
#include"AppleManager.h"

CGame::CGame(CSceneManager* pManager) :CScene(pManager) { //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
	//プレイヤーを動的確保
	player = new CPlayer(pManager);
	//アップルマネージャーを動的確保
	applemanager = new CAppleManager();
}

CGame::~CGame() {
	//動的確保したものを解放する
	delete player;
	delete applemanager;
}

CScene* CGame::Update() {
	applemanager->Update();
	player->Update();

	return this;
}

void CGame::Render()const {
	DrawFormatString(0, 0, GetColor(255, 255, 255),"ゲーム");
	applemanager->Render();
	player->Render();
}