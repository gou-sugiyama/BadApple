#pragma once
class CController;
//�V�[���̊��N���X
class CScene
{
protected:
	CController* Controller;
public:
	CScene(CController* pController) :Controller(pController) {};
	virtual ~CScene() { delete Controller; }	//�K�v�ɉ����Ă��̃V�[���̃f�X�g���N�^���Ăт������߉��z�֐�(�K�v�Ȃ��V�[�������邽�ߏ������z�֐��ɂ͂��Ȃ�)

	//�X�V
	virtual CScene* Update() = 0;	//�f�X�g���N�^�Ɠ��l
	//�`��
	virtual void Render()const {}	//�f�X�g���N�^�Ɠ��l
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


