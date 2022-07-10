#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
CAppleManager::CAppleManager()
{
	apple = new CApple[D_APPLE_MAX];
}
CAppleManager::~CAppleManager() { delete[] apple; }

//-------------------------
// ����
//-------------------------
void CAppleManager::CreateApple()
{	
	//�����S����\���Ȃ�m�ۂ��Ă��郁������������A�V���Ɋm�ۂ���
	for (int i = 0; i < D_APPLE_MAX; i++) {
		if (apple[i].GetisShow() == false) {
			apple[i].AppleInit(0);
			break;
		}
	}
	
}

//------------------------
// �X�V
//------------------------
void CAppleManager::Update() {

	//25�t���[����1�񐶐������݂�
	static int WaitTime = 0;
	if (!(++WaitTime % 25))CreateApple();

	//�����Ă��郊���S�̍X�V
	for (int i = 0; i < D_APPLE_MAX; i++) {

		if (apple[i].GetisShow() == true) {
			apple[i].Update();
		
		}
			//��ʊO�ɏo�����\���ɂ���
		if (apple[i].GetY() >= D_SCREEN_HEIGHT) {
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
			DrawFormatString(0, 100 + 20 * i, 0xFFFFFF, "apple[%d]:%d", i, (int)apple[i].GetisShow());
		}

	}
}