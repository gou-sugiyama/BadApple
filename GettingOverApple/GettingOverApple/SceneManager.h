#pragma once
class CController;
//シーンの基底クラス
class CScene
{
protected:
	CController* Controller;
public:
	CScene(CController* pController) :Controller(pController) {};
	virtual ~CScene() { delete Controller; }	//必要に応じてそのシーンのデストラクタを呼びたいため仮想関数(必要ないシーンもあるため純粋仮想関数にはしない)

	//更新
	virtual CScene* Update() = 0;	//デストラクタと同様
	//描画
	virtual void Render()const {}	//デストラクタと同様
};

//シーン管理クラス
class CSceneManager
{
private:	
	//今のシーンのポインタ
	CScene* scene;
	
public:
	
	CSceneManager(CScene* pScene) :scene(pScene) {};
	~CSceneManager() { 
		//持っているクラスを解放する
		delete scene; 
	}	

	//更新	
	CScene* Update();		//各シーンの更新を呼び出す
	//描画
	void Render()const { scene->Render(); }		//各シーンの更新を呼び出す
};


