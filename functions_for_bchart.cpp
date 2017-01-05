#include <iostream>
#include <iomanip>
#include <windows.h>
#include "head_ache.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//ф-ция добавляет новый столбец;
void AddBlock_1(Bar &barchart, int elem)
{
    int *BNames = new int[barchart.NumBars + 1];
    int *BLength = new int[barchart.NumBars + 1];

    if (barchart.NumBars > 0)
    {
        for (int i = 0; i < barchart.NumBars + 1; i++)
        {
            BNames[i] = barchart.BarsNames[i];
            BLength[i] = barchart.BarsLength[i];
        }
        delete[] barchart.BarsLength;
        delete[] barchart.BarsNames;
    }

    BNames[barchart.NumBars] = elem;
    BLength[barchart.NumBars] = 1;
    barchart.NumBars++;
    barchart.BarsNames = BNames;
    barchart.BarsLength = BLength;
}

//ф-ция увеличивает существующий столбец на один блок 
//и добавляет новый столбец, если эл-т встречен впервые;
void AddBlock_0(Bar &barchart, int elem)
{
    bool k = false;
    for (int i = 0; i < barchart.NumBars; i++)
    {
        if (barchart.BarsNames[i] == elem)
        {
            barchart.BarsLength[i]++;
            k = true;
            break;
        }

    }

    if (!k)
    {
        AddBlock_1(barchart, elem);
    }
}

//ф-ция создает массив символов и заполняет гистограмму;
void Create_A_BChart(Bar &barchart)
{
    int i=0,N;
    cout << "Input number of elements: ";
    cin >> N;
    int *massive = new int [N];
    for (i = 0; i<N; i++)
    {
        cout << "\nInput element #" << i+1<<" ";
        cin >> massive[i];
        AddBlock_0(barchart, massive[i]);
       
    }
}

//сортировка столбцов гистограммы методом "быстрой сортировки" по возрастанию;
void QSort_True(Bar &barchart, int k, int z)
{
    int Op = barchart.BarsNames[(k + z) / 2];
    int vedro = 0, i = k, j = z;
    while (i <= j)
    {
        while (barchart.BarsNames[i] < Op)
        {
            i++;
        }
        while (barchart.BarsNames[j] > Op)
        {
            j--;
        }
        if (i <= j)
        {
            //перестановка названий столбцов;
            vedro = barchart.BarsNames[i];
            barchart.BarsNames[i] = barchart.BarsNames[j];
            barchart.BarsNames[j] = vedro;
            //перестановка столбцов;
            vedro = barchart.BarsLength[i];
            barchart.BarsLength[i] = barchart.BarsLength[j];
            barchart.BarsLength[j] = vedro;

            i++;
            if (j > 0)
                j--;
        }
    }
    if (i < z)
    {
        QSort_True(barchart, i, z);
    }
    if (k < j)
    {
        QSort_True(barchart, k, j);
    }
    // 2 1 3 5 4
}

//сортировка столбцов гистограммы методом "быстрой сортировки" по убыванию;
void QSort_False(Bar &barchart, int k, int z)
{
    int Op = barchart.BarsNames[(k + z) / 2];
    int vedro = 0, i = k, j = z;
    while (i <= j)
    {
        while (barchart.BarsNames[i] > Op)
        {
            i++;
        }
        while (barchart.BarsNames[j] < Op)
        {
            j--;
        }
        if (i <= j)
        {
            //перестановка названий столбцов;
            vedro = barchart.BarsNames[i];
            barchart.BarsNames[i] = barchart.BarsNames[j];
            barchart.BarsNames[j] = vedro;
            //перестановка столбцов;
            vedro = barchart.BarsLength[i];
            barchart.BarsLength[i] = barchart.BarsLength[j];
            barchart.BarsLength[j] = vedro;

            i++;
            if (j > 0)
                j--;
        }
    }
    if (i < z)
    {
        QSort_False(barchart, i, z);
    }
    if (k < j)
    {
        QSort_False(barchart, k, j);
    }
}

//ф-ция организующая выбор метода сортировки;
void SortByName(Bar &barchart, bool bAscending)
{
    if (bAscending)
    {
       QSort_True(barchart, 0, barchart.NumBars - 1);
    }
    else
    { 
       QSort_False(barchart, 0, barchart.NumBars - 1);
    }
}

//ф-ция печати гистограммы на экран;
void Print_A_BChart(Bar &barchart, int normf)
{  
    char *bchart = "BAR CHART";
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hstdout, &csbi);

    system("cls");
    cout << endl<<"| BAR CHART |" << endl;

    for (int i = 0; i < barchart.NumBars; i++)
    {
        SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "| " << setw(9) << right << barchart.BarsNames[i] << " |";
        for (int k = 0; k < barchart.BarsLength[i]; k++)
        {
            if (barchart.BarsLength[i] > normf)
            {
                SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << barchart.ChartBlock << barchart.ChartBlock;
            }
            if (barchart.BarsLength[i] < normf)
            {
                SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << barchart.ChartBlock << barchart.ChartBlock;
            }
            if (barchart.BarsLength[i] == normf)
            {
                SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << barchart.ChartBlock << barchart.ChartBlock;
               
            }
           
        }
        cout << "\n";
    }
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl << "|- Chart Block: || -" << endl << "| ";
    SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "|";
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << " - normal frequency; " << endl << "| ";
    SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "|";
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << " - safe frequency " << endl << "| ";
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "|";
    SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << " - dangerous frequency " << endl << endl;
}
