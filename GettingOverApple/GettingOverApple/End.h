#pragma once
#include "SceneManager.h"
class CEnd :
    public CScene
{
private:
    int image;
public:
    CEnd(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
    ~CEnd() {}

    CScene* Update() override;
    void Render()const override;
};
