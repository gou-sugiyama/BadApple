#include "SceneManager.h"
#include "CRanking.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CRanking::CRanking(CController* pController) :CScene(pController) {

}

//--------------------------------
// �X�V
//--------------------------------
CScene* CRanking::Update() {
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void CRanking::Render()const {

}