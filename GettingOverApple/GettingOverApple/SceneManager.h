#pragma once
class CController;
//�V�[���̊��N���X
class CScene
{
protected:
	CController* controller;
public:
	CScene(CController* pController) :controller(pController) {};
	virtual ~CScene() {}	//�K�v�ɉ����Ă��̃V�[���̃f�X�g���N�^���Ăт������߉��z�֐�(�K�v�Ȃ��V�[�������邽�ߏ������z�֐��ɂ͂��Ȃ�)

	//�X�V
	virtual CScene* Update() = 0;	
	//�`��
	virtual void Render()const = 0;
};

//�V�[���Ǘ��N���X
class CSceneManager
{
private:	
	//���̃V�[���̃|�C���^
	CScene* scene;
	
public:
	
	CSceneManager(CScene* pScene) :scene(pScene) {};
	~CSceneManager() { 
		//�����Ă���N���X���������
		delete scene; 
	}	

	//�X�V	
	CScene* Update();		//�e�V�[���̍X�V���Ăяo��
	//�`��
	void Render()const { scene->Render(); }		//�e�V�[���̍X�V���Ăяo��
};


