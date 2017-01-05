/*
2.
—оздать функцию void rewriteNumbers(string &src), котора€ замен€ет все встречающиес€ прописные числа на их дес€тичную запись.
ѕрограмма должна работать дл€ чисел, которые меньше 100.
Ќапример (Уthirteen is my lucky numberФ -> У13 is my lucky numberФ.
*/
/*
12.
—оздать функцию void incrementEquals(string &src), котора€ увеличивает все одинаковые числа, встречающиес€ в строке на 1.
Ќапример (У33 magpies flew over the 33 roofs on September 13Ф -> У34 magpies flew over the 34 roofs on September 13Ф.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"
using namespace std;
int main()
{
    string str = " ";
    
    cout << "Input your string:" << endl;
    getline(cin,str);
    cout << "Rewriting numbers..." << endl << "Done:" << endl;
    /*if (!rewriteNumbers(str))
    {
     cout << str << endl;
    }
    */cout << "Incrementing equal numbers..." << endl << "Done:" << endl;
    incrementEquals(str);
        cout << str << endl;
    system("pause");
}