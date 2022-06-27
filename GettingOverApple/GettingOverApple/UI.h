#pragma once
class CUI
{
private:
	int AppleCount[4];
	int score;
	int TimeLimit;
	bool isPause;
public:
	CUI();
	void Render();
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

