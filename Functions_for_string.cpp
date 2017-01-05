#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
//#define _D_SCL_SECURE_NO_WARNINGS
using namespace std;

int rewriteNumbers(string &str)
{
    string str_1, str_2;
    int pos_s, pos_e;
    ifstream Nums("Numbers.txt", ios_base::in);
    if (!Nums.is_open())
    {
        cout << "ERROR reading file" << endl;
        return 1;
    }
     
    for (int i = 0; !Nums.eof(); i++)
    {

    Nums >> str_1;
    Nums >> str_2;
    // поиск цифры в строке
    while ((pos_s = str.find(str_2)) >= 0)
    {
        str.replace(pos_s, str_2.length(), str_1);
    }

    }

    Nums.close();
    return 0;
}
//void incrementEquals(string &str)
//{
//    string *str_1 = new string[50];
//    string str_2;
//    int k=0,i=0,n=0,pos_s=0, pos;
//    int pos_e = str.find(" ");
//    while ((pos_e = str.find(" ")) > 0)
//    {
//        str_1[n].assign(str,0, pos_e);
//        n++;
//        pos_s = pos_e;
//        str.assign(str, pos_e+1, str.length());
//    }
//    str_1[n++].assign(str, 0, str.length());
//    for (i = 0; i < n; i++)
//    {
//        if (atoi(str_1[i].c_str()))
//        {
//            for (int j = i + 1; j < n; j++)
//            {
//                if (str_1[j] == str_1[i])
//                {
//                    k++;
//                    pos = j;
//                }
//            }
//            if (k > 1)
//            {
//                str_1[i] = to_string(-1*(stoi(str_1[i]) + 1));
//            }
//            else if (k == 1)
//            {
//                str_1[i] = to_string(-1 * (stoi(str_1[i]) + 1));
//                str_1[pos] = str_1[i];
//            }
//            k = 0;
//        }
//    }
//        str = "";
//        for (i = 0; i <n; i++)
//        { 
//            if (atoi(str_1[i].c_str())<0)
//            {
//                str_1[i] = to_string(-1 * (stoi(str_1[i])));
//            }
//            str = str + str_1[i] + " ";
//        }
//    
//}
void incrementEquals(string &str)
{
    string *str_1 = new string[50];
    string str_2;
    int k = 0, j = 0, p = 0, i = 0, n = 0, pos_s = 0, pos;
    int pos_e = str.find(" ");
    while ((pos_e = str.find(" ")) > 0)
    {
        str_1[n].assign(str, 0, pos_e);
        n++;
        // pos_s = pos_e;
        str.assign(str, pos_e + 1, str.length());
    }
    str_1[n++].assign(str, 0, str.length());

    for (i = 0; i < n; i++)
    {

        if (atoi(str_1[i].c_str()))
        {
           
                    //string al = "213";
                    int numb = stoi(str_1[i]);
                    int numd = 0;
                    for (int b = 0; numb != 0; b++)
                    {
                        numd += (numb % 10)*pow(2,b);
                        numb /= 10;
                    }
                   // rewrite(line, a, numd);//токак переписать у тебя уверен есть 
                    str_1[i] = to_string(numd);
                
            }
        }
    
str = " ";
    for (i = 0; i <n; i++)
    {
        if (atoi(str_1[i].c_str())<0)
        {
            str_1[i] = to_string(-1 * (stol(str_1[i])));
        }
        str = str + str_1[i] + " ";
    }

}
void imaximizeNumbers(string &str)
{
    string *str_1 = new string[50];
    string str_2;
    int k = 0, i = 0, n = 0, pos_s = 0, min = INT_MAX;
    int pos_e = str.find(" ");

    while ((pos_e = str.find(" ")) > 0) /*пока не встретим пробел*/
    {
        str_1[n].assign(str, 0, pos_e);
        n++;
        pos_s = pos_e;
        str.assign(str, pos_e + 1, str.length());
    }
    str_1[n++].assign(str, 0, str.length());

    for (i = 0; i < n; i++)
    {
        if (atoi(str_1[i].c_str()) && atoi(str_1[i].c_str())<min)
        {
            min = stoi(str_1[i]);
        }
    }

    for (i = 0; i < n; i++)
    {
        if (atoi(str_1[i].c_str()))
        {
            str_1[i] = to_string(min);
        }
    }

    str = "";
    for (i = 0; i <n; i++)
    {

        str = str + str_1[i] + " ";
    }

}
void sortNumbers(string &str)
{
    string *str_1 = new string[50];
    string str_2, vedro;
    int k = 1, i = 0, n = 0, pos_s = 0;
    int pos_e = str.find(" ");

    while ((pos_e = str.find(" ")) > 0) /*пока не встретим пробел*/
    {
        str_1[n].assign(str, 0, pos_e);
        n++;
        pos_s = pos_e;
        str.assign(str, pos_e + 1, str.length());
    }
    str_1[n++].assign(str, 0, str.length());

    for (i = 0; i < n; i++) /*проходим по массиву строк*/
    {
        for (int j = 0; j < n - 1; j++)
        {
            while (k + j < n){
                if (atoi(str_1[j].c_str()) > atoi(str_1[j + k].c_str()) && (atoi(str_1[j + k].c_str()) || str_1[j+k] == "0")) /*если предыдущее число больше следующего, то пузырек*/
                {
                    vedro = str_1[j];
                    str_1[j] = str_1[j + k];
                    str_1[j + k] = vedro;
                    break;
                }   else k++;
            }
            k = 1;
        }
    }



    str = "";
    for (i = 0; i <n; i++)
    {

        str = str + str_1[i] + " ";
    }

}

