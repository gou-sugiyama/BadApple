#pragma once
class UserInterface
{
private:
	int m_AppleCount[4];
	int m_TimeLimit;
	bool isPause;
public:
	UserInterface();
	void Draw(void);
	bool getisPause() const {
		return isPause;
	}
};

