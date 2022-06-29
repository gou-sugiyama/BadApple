#include"DxLib.h"
#include"define.h"
#include"Apple.h"
#include"AppleManager.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
CAppleManager::CAppleManager()
{
	image = LoadGraph("images/Apple_2.png");

	apple = new CApple(image);

}CAppleManager::~CAppleManager() { delete apple; }

//-------------------------
// ����
//-------------------------
void CAppleManager::CreateApple()
{	
	//�����S����\���Ȃ�m�ۂ��Ă��郁������������A�V���Ɋm�ۂ���
	if (apple->GetisShow() == FALSE) {
		delete apple;
		apple = new CApple(image);
	}
}

//------------------------
// �X�V
//------------------------
void CAppleManager::Update() {
	//��ʊO�ɏo�����\���ɂ���
	if (apple->GetY() >= D_SCREEN_HEIGHT) {
		apple->ToggleisShow();
	}

	//25�b��1�񐶐������݂�
	static int WaitTime = 0;
	if (!(++WaitTime % 25)) CreateApple();

	//�l�������Ă��郊���S�̍X�V
	if (apple != NULL) {
		apple->Update();
	}
}

//-------------------------
// �`��
//-------------------------
void CAppleManager::Render()const {
	//�l�������Ă��郊���S������Ε`�悷��
	if (apple != NULL) {
		apple->Render();
	}
}