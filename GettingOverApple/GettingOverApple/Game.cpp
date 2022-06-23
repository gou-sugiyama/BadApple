#include"DxLib.h"
#include"Manager.h"
#include"Game.h"
#include"Title.h"
#include"Player.h"

CGame::CGame(CManager* pManager) :CScene(pManager) { //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
	//プレイヤーを動的確保
	player = new CPlayer(pManager);
}

CGame::~CGame() {
	//動的確保したものを解放する
	delete player;
}

void CGame::Update() {
	player->Update();
}

void CGame::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255),"ゲーム");
	player->Render();
}