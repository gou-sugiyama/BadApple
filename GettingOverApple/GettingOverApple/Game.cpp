#include"DxLib.h"
#include"Manager.h"
#include"Game.h"
#include"Title.h"
#include"Player.h"
#include"AppleManager.h"

CGame::CGame(CManager* pManager) :CScene(pManager) { //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
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

void CGame::Update() {
	applemanager->Update();
	player->Update();
}

void CGame::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255),"ゲーム");
	applemanager->Render();
	player->Render();
}