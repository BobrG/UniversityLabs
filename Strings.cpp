/*
2.
������� ������� void rewriteNumbers(string &src), ������� �������� ��� ������������� ��������� ����� �� �� ���������� ������.
��������� ������ �������� ��� �����, ������� ������ 100.
�������� (�thirteen is my lucky number� -> �13 is my lucky number�.
*/
/*
12.
������� ������� void incrementEquals(string &src), ������� ����������� ��� ���������� �����, ������������� � ������ �� 1.
�������� (�33 magpies flew over the 33 roofs on September 13� -> �34 magpies flew over the 34 roofs on September 13�.
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