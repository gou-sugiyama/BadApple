#include "Apple.h"
#include"DxLib.h"

CApple::CApple() {
	m_x = GetRand(6)*70;
	m_y = 30;
	m_w = 40;
	m_h = 40;
	image = LoadGraph("images/cone.bmp");
	speed = 3;
	score = 50;
}

void CApple::Draw()const {
	DrawGraph(m_x, m_y, image,true);
}

void CApple::Fall() {
	m_y += speed;
}