#include "SceneManager.h"
#include"Controller.h"
#include "Ranking.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CRanking::CRanking(CController* pController) :CScene(pController) {

}

//--------------------------------
// �X�V
//--------------------------------
CScene* CRanking::Update() {
	//controller->control(false);
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CRanking::Render()const {

}