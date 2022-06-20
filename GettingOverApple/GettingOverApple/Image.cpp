#include "Image.h"

int GameImage::LoadGameImage()
{
    if ((PlayerImage = LoadGraph("images/gentuki.bmp")) == -1)return -1;
    if ((AppleImage[0] = LoadGraph("images/.png")) == -1)return -1;
    if ((AppleImage[1] = LoadGraph("images/.png")) == -1)return -1;
    if ((AppleImage[2] = LoadGraph("images/.png")) == -1)return -1;
    if ((AppleImage[3] = LoadGraph("images/.png")) == -1)return -1;


    return 0;
}
