#pragma once

class CRanking :
    public CScene
{

private:
public:
    CRanking(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
    ~CRanking() {}

    CScene* Update() override;
    void Render()const override;
};