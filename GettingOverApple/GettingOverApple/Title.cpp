#include"DxLib.h"
#include"Manager.h"
#include"Title.h"
#include"Game.h"

void CTitle::Update() {
	if (*(manager->GetKey()) >= 1) {
		//�Q�[���V�[���Ɉڍs
		manager->scene = new CGame(manager);
		delete this;
	}
}

void CTitle::Render() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�^�C�g��");
}
