#include "DxLib.h"
#include"SceneManager.h"
#include"Title.h"
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


	//�Ǘ��V�X�e���𓮓I�m��
	CSceneManager* manager;
	manager = new CSceneManager(&g_NowKey);

	//�^�C�g���𓮓I�m��
	manager->scene = new CTitle(manager);

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && !(g_KeyFlg & PAD_INPUT_START) && manager->Update() != nullptr) {
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

	DxLib_End();					//DX���C�u�����g�p�̏I������
	return 0;				//�\�t�g�I��
}
