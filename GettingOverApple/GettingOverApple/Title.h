#pragma once
//タイトルの管理
class CTitle :
    public CScene
{
private:
public:
    CTitle(CController* pController) :CScene(pController) {}       //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
    ~CTitle() {}

    CScene* Update() override;
    void Render()const override;
};

