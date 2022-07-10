#include"DxLib.h"
#include "Rank.h"
#include"Controller.h"

CRanking::CRanking(FILE* fp)
{
#pragma warning(disable:4996)
	fscanf(fp, "%2d %10s %10d", Rank,Name,Score);
}


void CRanking::InsertRankChar(char* data)
{
}

void CRanking::Update()
{

}

void CRanking::Render() const
{
}
