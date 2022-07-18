#pragma once
#define D_COUNT_OBJECT 3
class CController;

class CUI
{
private:
	CController* controller;
	int objectCount[D_COUNT_OBJECT];
	int objectImage[D_COUNT_OBJECT];
	int score;
	int timeLimit;
	bool isPause;
public:
	CUI(CController* pController);
	bool Update();
	void Render()const;
	void DrawObjectCount()const;

	bool GetisPause() const {
		return isPause;
	}

	int GetScore() const{
		return score;
	}

	void SetScore(int add) {
		score += add;
		if (score < 0)score = 0;
	}

	void SetCount(int num) {
		if (0 <= num && num < D_COUNT_OBJECT)
		objectCount[num]++;
	}
};

