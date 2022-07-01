#pragma once
class CController;
//�V�[���̊��N���X
class CScene
{
protected:
	CController* controller;
public:
	CScene(CController* pController) {
		controller = pController;
	}	//���N���X�̈����t���R���X�g���N�^���ĂԂɂ́A��������: <���N���X��>(<���������X�g>) �Ə����B
	virtual ~CScene() {}

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


