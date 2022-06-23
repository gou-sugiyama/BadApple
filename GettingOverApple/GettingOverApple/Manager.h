#pragma once
class CManager;
//シーンの基底クラス
class CScene
{
protected:
	//動的確保するシーン管理クラスのポインタ
	CManager* manager;		//子クラス内でもmanagerにシーンを渡すために必要

public:
	CScene(CManager* pManager) { manager = pManager; };		//生成したときにmanagerのアドレスを引き継ぐ
	virtual ~CScene() {};	//必要に応じてそのシーンのデストラクタを呼びたいため仮想関数(必要ないシーンもあるため純粋仮想関数にはしない)

	//更新
	virtual void Update() {};	//デストラクタと同様
	//描画
	virtual void Render() {};	//デストラクタと同様
};

//シーン管理クラス
class CManager
{
private:
	//キー
	int* key;

public:
	//今のシーンのポインタ
	CScene* scene;			//mainで操作したい、クラス内で持ちたいものなのでpublicで宣言する。

	CManager(int* pKey)		//TODO:コンストラクタがいつ呼ばれているのかを見てキー入力のタイミングを確認する
	{
		key = pKey;
		scene = 0;
	};
	~CManager() { delete scene; };		//sceneは動的確保前提なので忘れないようにdeleteする

	int* GetKey() { return key; };

	//更新	
	void Update() { scene->Update(); };		//各シーンの更新を呼び出す
	//描画
	void Render() { scene->Render(); };		//各シーンの更新を呼び出す
};


