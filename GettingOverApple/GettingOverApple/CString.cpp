#include "CString.h"

CString::CString(int i)
{
		str_X = i % 13 * 30 + 60;
		str_Y = i / 13 * 60;
		image = LoadGraph("images/Test.png");
		bigimage = LoadGraph("images/Test2.png");
		string = 'A'+i;
		strflg = FALSE;
}

bool CString::GetStrFlg()
{
	return strflg;
}

void CString::SetStrFlg(bool i)
{
	strflg = i;
}

int CString::GetStrX()
{
	return str_X;
}

int CString::GetStrY()
{
	return str_Y;
}

int CString::GetImage()
{
	return image;
}

int CString::GetBigImage()
{
	return bigimage;
}

char CString::GetStr()
{
	return string;
}
