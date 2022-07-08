#include"DxLib.h"
#include "Rank.h"
#include"Controller.h"

CRanking::CRanking(FILE* fp)
{
	fscanf(fp, "%2d %10s %10d", Rank,Name,Score);
}


void CRanking::Update()
{
}
