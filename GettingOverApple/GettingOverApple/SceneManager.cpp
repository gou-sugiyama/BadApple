#include"SceneManager.h"

CScene* CSceneManager::Update(){
	CScene* p = scene->Update();
	if (p != scene) {
		delete scene;
		scene = p;
	}

	return p;
}