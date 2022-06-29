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

