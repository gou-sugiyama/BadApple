#include "DxLib.h"
#include"SceneManager.h"
#include"Controller.h"
#include"Title.h"
#include"Apple.h"
#include"UI.h"

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
	CController controller;

	//�Ǘ��V�X�e���𓮓I�m��
	CSceneManager* manager;
	manager = new CSceneManager(new CTitle(&controller));

	//�Q�[�����[�v
	while (ProcessMessage() == 0 
		&& manager->Update() != nullptr&& controller.GetControl().Buttons[5] != TRUE) {
		
		ClearDrawScreen();		//��ʂ̏�����


		controller.control(controller.GetControlFlg());

		manager->Render();

		ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f
	}

	//manager�̉��
	delete manager;


	DxLib_End();					//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�I��
}
