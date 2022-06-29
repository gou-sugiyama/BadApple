#include "DxLib.h"
#include"SceneManager.h"
#include"Controller.h"
#include"Title.h"
#include"Game.h"//TODO:����
#include"Apple.h"
#include"UI.h"
/*************************************************************************
*	�ϐ��̐錾
**************************************************************************/

int g_OldKey;	//�O��̓��̓L�[
int g_NowKey;	//����̓��̓L�[
int g_KeyFlg;	//���̓L�[���



/*************************************************************************
*	�v���O�����̊J�n
**************************************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpcmdLine, int nCmdShow) {
	SetMainWindowText("GettingOverApple");

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	//�R���g���[���̓��I�m��
	CController* controller;
	controller = new CController;

	//�Ǘ��V�X�e���𓮓I�m��
	CSceneManager* manager;
	manager = new CSceneManager(new CGame(controller));

	//�Q�[�����[�v
	while (ProcessMessage() == 0 
		&& manager->Update() != nullptr&& (controller->control(true)).Buttons[5] != TRUE) {
		//���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		//��ʂ̏�����

		manager->Render();

		ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f
	}

	//manager�̉��
	delete manager;
	//controller�̉��
	delete controller;


	DxLib_End();					//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�I��
}
