#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

//-------------------------------------------------
// �����e�[�u���̍쐬�@�@�{���Ȃ�w�b�^�[�����܂�
//-------------------------------------------------
int* GetRandTable(int* t, int size,int randMax) {
	int i = 0;
	bool retake;
	while (i < size) {
		retake = false;
		t[i] = GetRand(randMax);
		for (int j = 0; j < i; j++) {
			if (t[j] == t[i]) {
				retake = true;
				break;
			}
		}

		if (retake == true)continue;
		i++;
	}
	return t;
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
			"apple[%d]:%d   y:%.0f x:%.0f", 
			i, (int)apple[i].GetS(),apple[i].GetY(),apple[i].GetX());
	}
}

//-------------------------
// ���� 
//-------------------------
void CAppleManager::CreateApple(int tasks)
{	
	if (tasks) {
		int* RandTable = new int[tasks];
		GetRandTable(RandTable, tasks, D_CREATE_POINT_NUM - 1);

		//�����S����\���Ȃ��񂲂�����������
		for (int i = 0; i < D_APPLE_MAX; i++) {
			if (apple[i].GetisShow() == false) {
				apple[i].NewApple((float)((RandTable[--tasks] + 0.5) * (D_GAME_AREA / D_CREATE_POINT_NUM)));
				if (tasks <= 0)break;
			}
		}

		delete[] RandTable;
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