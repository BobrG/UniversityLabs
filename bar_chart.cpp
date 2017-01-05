/* 
Лабараторная работа 1.
Бобровских Глеб А.
Группа БПМ155.
Вариант 2.
(Добавил запрос на ввод "нормы" частоты встреч чисел в массиве
 для обоснования колоризации столбцов гистограммы)
*/
#include <iostream>
#include <iomanip>
#include "head_ache.h"
using namespace std;

int main()
{
    Bar barchart;
    bool bAscending = 1;
    int normf = 0;

    Set_Up_BChart(barchart);

    Create_A_BChart(barchart);

    cout << endl;
    cout << " - Input normal frequency: ";
    cin >> normf;
    
    Print_A_BChart(barchart, normf);

    cout << endl << "| - Do you wanna sort the bar chart? -" << endl;
    cout << "| - Yes - 1" << endl << "| - No  - 0" << endl;
    cin >> bAscending;

    if (bAscending)
    {
        cout << "| - Bars Increasing - 1"<< endl << "| - Bars Decreasing - 0" << endl;
        cin >> bAscending;
        SortByName(barchart,bAscending);
        Print_A_BChart(barchart, normf);
    }

    Delete_A_BChart(barchart);

    system("pause");
}