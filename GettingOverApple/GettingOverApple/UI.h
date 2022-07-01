#pragma once
class CController;

class CUI
{
private:
	CController* controller;
	int appleCount[4];
	int score;
	int timeLimit;
	bool isPause;
public:
	CUI(CController* pController);
	bool Update();
	void Render()const;

	bool GetisPause() const {
		return isPause;
	}

	int GetScore() const{
		return score;
	}

	void SetScore(int add) {
		score += add;
	}
};

