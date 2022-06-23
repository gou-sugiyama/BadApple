#include "Apple.h"
#include"DxLib.h"
#include"AppleManager.h"

CApple::CApple(int pimage) {
	m_x = GetRand(6)*70;
	m_y = 0;
	m_w = D_APPLE_WIDTH;
	m_h = D_APPLE_HEIGHT;
	image = pimage;
	speed = 3;
	score = 50;
	isShow = true;
}

void CApple::Update() {
	m_y += speed;
}

void CApple::Render() {
	DrawGraph(m_x, m_y, image,true);
}

void CApple::toggleisShow() {
	isShow = !isShow;
}