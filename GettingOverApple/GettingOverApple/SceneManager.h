#pragma once
class CSceneManager;
//シーンの基底クラス
class CScene
{
protected:
	//動的確保するシーン管理クラスのポインタ
	CSceneManager* manager;		//シーン内でクラスにマネージャーを渡したい
public:
	CScene(CSceneManager* pManager) { manager = pManager; }		//生成したときにmanagerのアドレスを引き継ぐ
	virtual ~CScene() {};	//必要に応じてそのシーンのデストラクタを呼びたいため仮想関数(必要ないシーンもあるため純粋仮想関数にはしない)

	//更新
	virtual CScene* Update() = 0;	//デストラクタと同様
	//描画
	virtual void Render()const {}	//デストラクタと同様
};

//シーン管理クラス
class CSceneManager
{
private:
	//キー
	int* key;
	//今のシーンのポインタ
	

public:
	CScene* scene;

	CSceneManager(int* pKey)		//TODO:コンストラクタがいつ呼ばれているのかを見てキー入力のタイミングを確認する
	{
		key = pKey;
		scene = 0;
	}
	~CSceneManager() { delete scene; }	//sceneは動的確保前提なので忘れないようにdeleteする

	int* GetKey() { return key; }

	//更新	
	CScene* Update();		//各シーンの更新を呼び出す
	//描画
	void Render()const { scene->Render(); }		//各シーンの更新を呼び出す
};


