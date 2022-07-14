#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

//-------------------------------------------------
// �����e�[�u���̍쐬�@�@�{���Ȃ�w�b�^�[�����܂�
//-------------------------------------------------
int* GetRandTable(int t[]) {
	int tMax = sizeof(t);

	return nullptr;
}

//-----------------------
// �R���X�g���N�^
//-----------------------
CAppleManager::CAppleManager()
{
	apple = new CApple[D_APPLE_MAX];
	CreateApple(D_STARTER_APPLE);
}

//-----------------
// �f�X�g���N�^
//-----------------
CAppleManager::~CAppleManager() { delete[] apple; }

//------------------------
// �X�V
//------------------------
void CAppleManager::Update() {

	//25�t���[����1�񐶐������݂�
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) {
		//�c���Ă���g�̔����̐��̃����S�𐶐�����
		CreateApple((D_APPLE_MAX - CountApple()) / 2);
	}

	//�����Ă��郊���S�̍X�V
	for (int i = 0; i < D_APPLE_MAX; i++) {

		if (apple[i].GetisShow() == true) {
			apple[i].Update();
		}
		//��ʊO�ɏo�����\���ɂ���
		if (apple[i].GetY() >= D_SCREEN_HEIGHT && apple[i].GetisShow()) {
			apple[i].ToggleisShow();
		}
	}
}
//-------------------------
// �`��
//-------------------------
void CAppleManager::Render()const {
	//�����Ă��郊���S�̕`��
	for (int i = 0; i < D_APPLE_MAX; i++) {

		if (apple[i].GetisShow() == true) {
			apple[i].Render();
		}
		DrawFormatString(0, 100 + 20 * i, 0xFFFFFF, 
			"apple[%d]:%d   y:%.0f x:%.0f", i, (int)apple[i].GetisShow(),apple[i].GetY(),apple[i].GetX());
	}
}

//-------------------------
// ���� 
//-------------------------
void CAppleManager::CreateApple(int tasks)
{	
	//�����S����\���Ȃ��񂲂�����������
	for (int i = 0; i < D_APPLE_MAX; i++) {
		if (apple[i].GetisShow() == false) {
			apple[i].NewApple((float)((GetRand(D_CREATE_POINT_NUM - 1) + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM)));
			if (--tasks <= 0)break;
		}
	}
	
}

//------------------------
// ��ʓ��̃����S�𐔂���
//------------------------
int CAppleManager::CountApple() {
	int count = 0;
	for (int i = 0; i < D_APPLE_MAX; i++) {
		if (apple[i].GetisShow() == true) {
			count++;
		}
	 }
	return count;
}