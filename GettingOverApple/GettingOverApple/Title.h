#pragma once
//タイトルの管理

class CTitle :
    public CScene
{
public:
    CTitle(CManager* pManager) :CScene(pManager) {};        //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
    ~CTitle() {};

    void Update() override;
    void Render() override;
};

