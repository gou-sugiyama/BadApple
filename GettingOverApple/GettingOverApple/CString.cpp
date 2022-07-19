#include "RankMng.h"

CString::CString(int i)
{
	str_X = i % 13 * 30 + 60;
	str_Y = i / 13 * 60;
	image = LoadGraph("images/Test.png");
	bigimage = LoadGraph("images/Test2.png");
	if (i / 26 == 0) {
		string = 'A' + i % 26;
	}
	else if (i / 26 == 1) {
		string = 'a' + i % 26;
	}
	else if (i / 26 == 2) {
		if (i % 26 < 10) {
			string = '0' + i % 26;
		}
		else if (i % 26 == 10) {
			string = '(';
		}
		else if (i % 26 == 11) {
			string = ')';
		}
		else {

		}
	}


	strflg = FALSE;
}