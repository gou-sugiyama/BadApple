#include"DxLib.h"
#include"SceneManager.h"
#include"Game.h"
#include"Title.h"
#include"player.h"
#include"AppleManager.h"
#include"RankMng.h"
#include"UI.h"
#include"Hit.h"

CGame::CGame(CController* pController):CScene(pController){ 
	//�摜�̊i�[
	image = LoadGraph("images/haikei.png");
	//�󂯎�����R���g���[���̊i�[
	controller = pController;
	//�R���g���[���[�̃t���O��ύX
	controller->ToggleControlFlg();		//�t���O��FALSE�֕ύX
	//�v���C���[�𓮓I�m��
	player = new CPlayer(controller);
	//�A�b�v���}�l�[�W���[�𓮓I�m��
	appleManager = new CAppleManager();
	//�A�b�v���}�l�[�W���[���烊���S���擾
	apple = appleManager->GetpApple();
	//UI�𓮓I�m��
	UI = new CUI(controller);
	//Hit
	hit = new CHitBoxCheck;

	keyInput = controller->control(false);
}

CGame::~CGame() {
	//���I�m�ۂ������̂��������

	//�R���g���[���[�̃t���O��ύX
	controller->ToggleControlFlg();		//�t���O��TRUE�֕ύX

	delete player;
	delete appleManager;
	delete UI;
	delete hit;
}

CScene* CGame::Update() {
	keyInput = controller->control(false);
	//�Q�[����(�������ԓ��A�|�[�Y���ł͂Ȃ�)�Ȃ�X�V����
	if (UI->Update()) {//�Q�[����(�������ԓ��A�|�[�Y���ł͂Ȃ�)���ǂ�����Ԃ�
		if (UI->GetisPause() != true) {
			appleManager->Update();
			player->Update();
			for (int i = 0; i < D_APPLE_MAX; i++) {
				if (player->GetTnos() <= 0 && hit->HitBox(player, &apple[i])) {
					UI->SetCount(apple[i].GetType());
					UI->SetScore(apple[i].GetScore());
				}

			}
		}
	}
	else {
		//�������Ԑ؂�̎��A3�b��ɉ�ʑJ��
		static int WaitTime = 0;
		if (++WaitTime > 180) {
			WaitTime = 0;
			controller->SetScore(UI->GetScore());
			return new CRankMng(controller);
			rankmng->SetScore(UI->GetScore());
		}
	}
	return this;
}

void CGame::Render()const {
	DrawGraph(0, 0, image, FALSE);
	appleManager->Render();
	player->Render();
	UI->Render();
}