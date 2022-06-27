#pragma once
class CSceneManager;
class CUI
{
private:
	CSceneManager* manager;
	int AppleCount[4];
	int score;
	int TimeLimit;
	bool isPause;
public:
	CUI(CSceneManager* pSceneManager);
	bool Update();
	void Render()const;

	bool getisPause() const {
		return isPause;
	}

	int getScore() const{
		return score;
	}

	void setScore(int add) {
		score += add;
	}
};

