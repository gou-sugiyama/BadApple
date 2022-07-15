#include"DxLib.h"
#include"Player.h"
#include"Controller.h"
#include"define.h"

//-----------------------
// �R���X�g���N�^
//-----------------------
CPlayer::CPlayer(CController* pController) {
	//controller�̃A�h���X�i�[
	controller = pController;
	//�摜�f�[�^
	image = new int[D_PLAYER_IMAGE_MAX];
	image[false] = LoadGraph("images/taiki.png");
	image[true] = LoadGraph("images/run.png");
	//�摜���
	width = D_PLAYER_WIDTH;
	height = D_PLAYER_HEIGHT;

	//�ʒu��������(���W�� x:�Q�[���̈�̒��S, y:�E�C���h�E�̉���)
	x = (float)(D_GAME_AREA / 2);
	y = (float)(D_SCREEN_HEIGHT - (height / 2));	//RotaGraph�ŕ`�悷�邽�߉摜�T�C�Y��2���̈�ɂ���

	//�����蔻��p�ϐ�
	rangeX = (float)(width / 2);
	rangeY = (float)(height / 2);

	speed = 0;
	direction = 0;
	isMove = false;
}

CPlayer::~CPlayer() {
	delete[] image;
}

//------------------------
// �X�V
//------------------------
void CPlayer::Update() {
	//�X�s�[�h�̉��Z
	AddSpeed();

	//�ړ����Ȃ瓖���蔻���ς���
	SetWH();

	//speed�̍ő�l�A�ŏ��l�A���_�̐���
	SpeedControl();

	//�ʒu���̍X�V
	x += speed;
	//�Q�[���̈�̒[�Ŏ~�߂�
	if (x < D_PLAYER_WIDTH_MOVE) x = D_PLAYER_WIDTH_MOVE;		//���[
	if (x > D_GAME_AREA - D_PLAYER_WIDTH_MOVE)x = D_GAME_AREA - D_PLAYER_WIDTH_MOVE;		//���[
}

//-------------------------
// �`��
//-------------------------
void CPlayer::Render()const {
	DrawRotaGraph((int)x, (int)y, 1.0f, 0, image[isMove],
		TRUE, TRUE * direction);

	DrawFormatString(0, 20, 0xFFFFFF, "%lf", this->x);
	DrawFormatString(0, 40, 0xFFFFFF, "%lf", this->speed);
	DrawFormatString(0, 60, 0xFFFFFF, "%d", this->width);
	DrawFormatString(0, 80, 0xFFFFFF, "%d", this->height);
}

//-----------------------
// �X�s�[�h�̉��Z
//-----------------------
void CPlayer::AddSpeed() {
	//���փL�[���͒�speed��x�}�C�i�X�����ɉ��Z
	if (KeyControl() == 0) {
		speed -= D_PLAYER_ADD_SPEED;
		isMove = true;
	}

	//�E�փL�[���͒�speed��x�v���X�����ɉ��Z
	if (0 < KeyControl()) {
		speed += D_PLAYER_ADD_SPEED;
		isMove = true;
	}
}

//------------------------
// �X�s�[�h�̐���
//------------------------
void CPlayer::SpeedControl() {
	//�ő�l�A�ŏ��l�̐���
	if (speed < -D_PLAYER_MAX_SPEED)speed = -D_PLAYER_MAX_SPEED;
	if (speed > D_PLAYER_MAX_SPEED)speed = D_PLAYER_MAX_SPEED;

	//���t���[��speed��0�ɏ������߂Â��A0�ɂȂ�����ړ��t���O��false����
	if (speed > 0) {
		speed -= D_PLAYER_SUB_SPEED;
		if (speed < 0) {
			speed = 0;
		}
	}
	if (speed < 0) {
		speed += D_PLAYER_SUB_SPEED;
		if (speed > 0) {
			speed = 0;
		}
	}
	if (speed == 0) isMove = false;
}

//----------------------------
// �����蔻��̐؂�ւ�
//----------------------------
void CPlayer::SetWH() {
	//�ړ���
	if (isMove) {
		width = D_PLAYER_WIDTH_MOVE;
		height = D_PLAYER_HEIGHT_MOVE;
	}
	//�ҋ@��
	else {
		width = D_PLAYER_WIDTH;
		height = D_PLAYER_HEIGHT;
	}
}

//------------------------
// �L�[���͐���
//------------------------
int CPlayer::KeyControl() {
	short int key = (controller->GetKey()).ThumbLX;

	if (D_KEY_CONTROL_RIGHT < key) {			//�X�e�B�b�N���E�ɓ|���ꂽ��
		direction = 1;
		return 1;//�E
	}
	else if (key < D_KEY_CONTROL_LEFT) {		//�X�e�B�b�N�����ɓ|���ꂽ��
		direction = 0;
		return 0;//��
	}
	else {
		return -1;
	}
}

//------------------
// ����������
//------------------
void CPlayer::HitAction() {

}