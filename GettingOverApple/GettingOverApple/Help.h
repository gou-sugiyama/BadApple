#pragma once
class CHelp :
    public CScene
{
private:
    int image;
public:
    CHelp(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
    ~CHelp() {}

    CScene* Update() override;
    void Render()const override;
};