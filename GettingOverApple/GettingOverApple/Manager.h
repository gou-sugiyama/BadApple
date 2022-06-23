#pragma once
class CManager;
//�V�[���̊��N���X
class CScene
{
protected:
	//���I�m�ۂ���V�[���Ǘ��N���X�̃|�C���^
	CManager* manager;		//�q�N���X���ł�manager�ɃV�[����n�����߂ɕK�v

public:
	CScene(CManager* pManager) { manager = pManager; };		//���������Ƃ���manager�̃A�h���X�������p��
	virtual ~CScene() {};	//�K�v�ɉ����Ă��̃V�[���̃f�X�g���N�^���Ăт������߉��z�֐�(�K�v�Ȃ��V�[�������邽�ߏ������z�֐��ɂ͂��Ȃ�)

	//�X�V
	virtual void Update() {};	//�f�X�g���N�^�Ɠ��l
	//�`��
	virtual void Render() {};	//�f�X�g���N�^�Ɠ��l
};

//�V�[���Ǘ��N���X
class CManager
{
private:
	//�L�[
	int* key;

public:
	//���̃V�[���̃|�C���^
	CScene* scene;			//main�ő��삵�����A�N���X���Ŏ����������̂Ȃ̂�public�Ő錾����B

	CManager(int* pKey)		//TODO:�R���X�g���N�^�����Ă΂�Ă���̂������ăL�[���͂̃^�C�~���O���m�F����
	{
		key = pKey;
		scene = 0;
	};
	~CManager() { delete scene; };		//scene�͓��I�m�ۑO��Ȃ̂ŖY��Ȃ��悤��delete����

	int* GetKey() { return key; };

	//�X�V	
	void Update() { scene->Update(); };		//�e�V�[���̍X�V���Ăяo��
	//�`��
	void Render() { scene->Render(); };		//�e�V�[���̍X�V���Ăяo��
};


