// 1780.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include<stdio.h>
void FineSquare(int** ppMap, int nLength,int nDivide, int nFirstRow,int nFirstCol, int *ppNumCount);
int main()
{

	int **ppMap(nullptr);
	int nN(0);
	int nDivide(0);
	int *pNumCount;

	scanf_s("%d", &nN);
	ppMap = new int*[nN];
	
	
	for (int i = 0; i < nN; i++)
	{
		*(ppMap+i) = new int[nN];
	}

	pNumCount = new int[3];

	for (int i = 0; i < 3; i++)
	{
		pNumCount[i] = 0;
	}

	for (int i = 0; i < nN; i++)
	{
		for (int j = 0; j < nN; j++)
		{
			scanf_s("%d", &ppMap[i][j]);
		}
	}
	FineSquare(ppMap, nN, nN, 0, 0, pNumCount);


	printf("%d\n%d\n%d", pNumCount[0], pNumCount[1], pNumCount[2]);
	return 0;
}

void FineSquare(int** ppMap, int nLength, int nDivide, int nFirstRow, int nFirstCol, int *ppNumCount)
{
	int nFirstData(0);
	int nRowIndex(0);
	int nColIndex(0);
	bool bSquare(false);
	int nDividing(0);
	nFirstData = ppMap[nFirstRow][nFirstCol];
	nRowIndex = nFirstRow;
	nColIndex = nFirstCol;

	if (nDivide <= 1)
	{
		ppNumCount[nFirstData + 1] += 1;

		return;
	}
	
	while (nRowIndex < nFirstRow + nDivide && nFirstData == ppMap[nRowIndex][nColIndex])
	{
		nColIndex++;
		if (nColIndex == nFirstCol+nDivide)
		{
			nColIndex = nFirstCol;
			nRowIndex++;
		}
		
	}
	if (nRowIndex == nFirstRow + nDivide)
	{
		nRowIndex--;
	}

	if (nFirstData == ppMap[nRowIndex][nColIndex])
	{
		bSquare = true;
	}
	if (bSquare)
	{
		ppNumCount[nFirstData + 1] += 1;

	}
	else
	{
		nDividing = nDivide / 3;
		FineSquare(ppMap,nDivide,nDividing,nFirstRow,nFirstCol,ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow, nFirstCol + nDividing, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow , nFirstCol + nDividing * 2, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow + nDividing, nFirstCol, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow + nDividing, nFirstCol + nDividing, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow + nDividing, nFirstCol + nDividing * 2, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow + nDividing*2, nFirstCol, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow + nDividing*2, nFirstCol + nDividing, ppNumCount);
		FineSquare(ppMap, nDivide, nDividing, nFirstRow + nDividing*2, nFirstCol + nDividing * 2, ppNumCount);
	}
	


}
