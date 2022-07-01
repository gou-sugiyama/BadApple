#include"DxLib.h"
#include"SceneManager.h"

CScene* CSceneManager::Update(){
	
	//�V�[���̍X�V���ĂтA���̃V�[����p�ɓǂݍ���
	CScene* p = scene->Update();

	//���̃V�[���ƌ��݂̃V�[�����Ⴄ�Ȃ獡�̃V�[�����폜���A���̃V�[�����Z�b�g����
	if (p != scene) {
		delete scene;
		scene = p;
	}

	return p;
}