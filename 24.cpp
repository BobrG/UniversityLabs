#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
/*
������� ������� void reverseNumbers(string &src), ������� ������������ ��� ����� ������� �������������� �����, � �������� �������.
�������� (�256� -> �31 is better than 23 even than 652�.
*/
void reverseNumbers(string &str)
{
    string *str_1 = new string[50]; // ������ ���� ���� string;
    int i, j,k, pos=0;
    string vedro_1,vedro_2; // ������ ��� ����� ��������� ������ ������� (��������� �������);
    // ������� ������ str �� �������� �� ����� � ���������� �������
    // ���� � ������ ����� str_1;  
    for (i = 0; (pos = str.find(" ")) > 0; i++)
    {
        str_1[i].assign(str,0,pos); // �������� ��������� ������ str � ������� 0 - ������ ������
                                    // �� ������� pos - ������ ������� ������� � ������ str;
        str.assign(str, pos+1, str.length()); // �������� ��� ������ str ������� � ������� ����� ������� ������� � ��� �� ����
                                            // ����� ����� ����� ���������� ������ ������ ���������� ������ ����� �� ������;
    }
    str_1[i++] = str.assign(str, 0, str.length());
    for (j = 0; j < i; j++)
    {
        if (atoi(str_1[j].c_str())) // ���� ������ �������� �����;
        {
            for (k = 0; k < str_1[j].length()/2; k++) // ���� �� ������ � ���� ������ �� ��������
            {                                         // � ������ ������� ��������� ������� � ������ � �.�.
            // ������������ ����� ���� � ������� ������� replace, � � vedro_1/2 ���������� �������� ������� ������ �������;
                vedro_1.assign(str_1[j], k, 1);
                vedro_2.assign(str_1[j], str_1[j].length() - k-1, 1);
                str_1[j].replace(k,1, vedro_2);
                str_1[j].replace(str_1[j].length() - k-1, 1, vedro_1);
            }
        }
    }
    str = "";
    for (k = 0; k < i; k++)
    {
        str = str + str_1[k] /*+ " "*/; // ��������� ������ �� ������� ����� str_1 ������� � ������ str;
    }

}
void maximizeNumbers(string &str)
{
    string *str_1 = new string[50];
    string str_2;
    int k = 0, i = 0, n = 0, pos_s = 0, pos, min = INT_MIN;
    int pos_e = str.find(" ");
    while ((pos_e = str.find(" ")) > 0)
    {
        str_1[n].assign(str, 0, pos_e);
        n++;
        pos_s = pos_e;
        str.assign(str, pos_e + 1, str.length());
    }
    str_1[n++].assign(str, 0, str.length());

    for (i = 0; i < n; i++)
    {
        if (stoi(str_1[i]))
        {
            for (int j = i + 1; j < n; j++)
            {
                if (str_1[i] < min)
                {
                    min = str_1[i];
                    pos = i;
                }
            }
            if (k > 1)
            {
                str_1[i] = to_string(-1 * (stoi(str_1[i]) + 1));
            }
            else if (k == 1)
            {
                str_1[i] = to_string(-1 * (stoi(str_1[i]) + 1));
                str_1[pos] = str_1[i];
            }
            k = 0;
        }
    }
    str = "";
    for (i = 0; i <n; i++)
    {
        if (stoi(str_1[i])<0)
        {
            str_1[i] = to_string(-1 * (stoi(str_1[i])));
        }
        str = str + str_1[i] + " ";
    }

}