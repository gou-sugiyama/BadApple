#pragma once
#include"DxLib.h"

class CString
{
private:
    int str_X;
    int str_Y;
    int image;
    int bigimage;
    char string;
    bool strflg;

public: 

    CString(int i);

    bool GetStrFlg();
    void SetStrFlg(bool i);
    int GetStrX();
    int GetStrY();
    int GetImage();
    int GetBigImage();
    char GetStr();

};

