#pragma once
#define D_MENU_WIDTH (195)
#define D_MENU_HEIGHT (40)
#define D_MENU_MARGIN (40)

//タイトルの管理
class CTitle :
    public CScene
{
private:
    int titleImage;
    int startImage;
    int rankingImage;
    int helpImage;
    int endImage;
    int menuCursor;

public:
    CTitle(CController* pController);      //基底クラスの引数付きコンストラクタを呼ぶには、実装時に: <基底クラス名>(<実引数リスト>) と書く。
    ~CTitle() {}

    CScene* Update() override;
    void Render()const override;
};

