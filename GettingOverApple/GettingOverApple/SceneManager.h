#pragma once
class CSceneManager;
//�V�[���̊��N���X
class CScene
{
protected:
	//���I�m�ۂ���V�[���Ǘ��N���X�̃|�C���^
	CSceneManager* manager;		//�V�[�����ŃN���X�Ƀ}�l�[�W���[��n������
public:
	CScene(CSceneManager* pManager) { manager = pManager; }		//���������Ƃ���manager�̃A�h���X�������p��
	virtual ~CScene() {};	//�K�v�ɉ����Ă��̃V�[���̃f�X�g���N�^���Ăт������߉��z�֐�(�K�v�Ȃ��V�[�������邽�ߏ������z�֐��ɂ͂��Ȃ�)

	//�X�V
	virtual CScene* Update() = 0;	//�f�X�g���N�^�Ɠ��l
	//�`��
	virtual void Render()const {}	//�f�X�g���N�^�Ɠ��l
};

//�V�[���Ǘ��N���X
class CSceneManager
{
private:
	//�L�[
	int* key;
	//���̃V�[���̃|�C���^
	

public:
	CScene* scene;

	CSceneManager(int* pKey)		//TODO:�R���X�g���N�^�����Ă΂�Ă���̂������ăL�[���͂̃^�C�~���O���m�F����
	{
		key = pKey;
		scene = 0;
	}
	~CSceneManager() { delete scene; }	//scene�͓��I�m�ۑO��Ȃ̂ŖY��Ȃ��悤��delete����

	int* GetKey() { return key; }

	//�X�V	
	CScene* Update();		//�e�V�[���̍X�V���Ăяo��
	//�`��
	void Render()const { scene->Render(); }		//�e�V�[���̍X�V���Ăяo��
};


