#pragma once


typedef struct
{
    int *BarsNames;
    int *BarsLength;
    int  NumBars;
    char ChartBlock;
} Bar;

void inline Set_Up_BChart(Bar &barchart);
void inline Delete_A_BChart(Bar &barchart);
void Create_A_BChart(Bar &barchart);
void Print_A_BChart(Bar &barchart, int normf);
void SortByName(Bar &barchart, bool bAscending=true);

#include "Hidden.inl"