#include"DxLib.h"
#include "SceneManager.h"
#include"Controller.h"
#include "End.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CEnd::CEnd(CController* pController) :CScene(pController) {
	image = LoadGraph("images/haikei.png");
}

//--------------------------------
// 更新
//--------------------------------
CScene* CEnd::Update() {
	static int limit = 180;
	if (limit-- < 0) {
		return nullptr;
	}
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void CEnd::Render()const {
	DrawGraph(0, 0, image, FALSE);

	SetFontSize(24);
	DrawString(100, 170 + scrolY, "タイトル　　　リンゴ落とし", 0xf50f05);
	DrawString(100, 200 + scrolY, "バージョン　　1.0", 0x000000);
	DrawString(100, 230 + scrolY, "最終更新日　　2022年07月20日", 0x000000);
	DrawString(100, 260 + scrolY, "制作者　　　　国際電子ビジネス専門学校", 0x000000);
	DrawString(100, 290 + scrolY, "　　　　　　　		チーム2-3d", 0x000000);
	DrawString(100, 310 + scrolY, "素材利用", 0x000000);
	DrawString(100, 340 + scrolY, "　BGM　　　 　魔王魂", 0x000000);
	DrawString(100, 365 + scrolY, "　SE　　　　　魔王魂", 0x000000);
}