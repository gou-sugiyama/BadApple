#include"DxLib.h"
#include"SceneManager.h"

CScene* CSceneManager::Update(){
	
	//シーンの更新を呼びつつ、次のシーンをpに読み込む
	CScene* p = scene->Update();

	//次のシーンと現在のシーンが違うなら今のシーンを削除し、次のシーンをセットする
	if (p != scene) {
		delete scene;
		scene = p;
	}

	return p;
}