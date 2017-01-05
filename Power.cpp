//Написать класс, реализующий понятие Cила. Реализовать операции сложения, вычитания, умножения на число (перегрузка операторов).
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
class Force
{
private:
    vector<int> F; // контейнер типа vector для хранения вектора силы, который является вектором в R^3;
public:
    Force()// конструктор собирающий пустой вектор из трех элементов с нулями;
    {
        F.resize(3);
        F[0] = F[1] = F[2] = 0;
    }
    Force(int x, int y, int z)// конструктор для определенной силы F;
    {
        F.resize(3);
        F[0] = x;
        F[1] = y;
        F[2] = z;
    }
    Force operator +(const Force &f) const// перегрузка суммы (сумма сил); 
    {
        Force Ff;
        Ff.F[0] = F[0] + f.F[0];
        Ff.F[1] = F[1] + f.F[1];
        Ff.F[2] = F[2] + f.F[2];
        return Ff;
    }
    Force operator -(Force &f) const// перегрузка разности;
    {
        Force Ff;
        Ff.F[0] = F[0] - f.F[0];
        Ff.F[1] = F[1] - f.F[1];
        Ff.F[2] = F[2] - f.F[2];
        return Ff;
    }
    Force operator *(int a) const// умножение на число;
    {
        Force Ff;
        Ff.F[0] = F[0] * a;
        Ff.F[1] = F[1] * a;
        Ff.F[2] = F[2] * a;
        return Ff;
    }
    double Magnitude() const// модуль силы (длина) вектора;
    {
        return (sqrt(pow(F[0],2) + pow(F[1],2) + pow(F[2],2)));
    }
    friend istream& operator >>(istream& istr, Force &f);
    friend ostream& operator <<(ostream& ostr,const Force &f);
    ~Force()// деструктор, удаляет vector;
    {
        F.clear();
    }
};
ostream& operator <<(ostream& ostr, const Force &f)
{
    ostr << "(" << f.F[0] << "," << f.F[1] << "," << f.F[2] << ")" << endl;
    return ostr;
}
class Errors
{
private:
    vector<char*> value;
    vector<char> valuename;
public: 
    Errors(char x =0 , char* a = 0 , char y = 0, char* b = 0, char z = 0, char* c = 0)
    {
        value.resize(3);
        valuename.resize(3);
        for (int i = 0; i < 3; i++)
        {
        value[i] = new char[20];
        }
        strcpy(value[0], a);
        valuename[0] = x;
        strcpy(value[1], b);
        valuename[1] = y;
        strcpy(value[2], c);
        valuename[2] = z;
    }
    void print_value()
    {
        for (int i = 0; i < 3; i++)
        {
            if (!atoi(value[i]))
            {
                cout << valuename[i] << " " << value[i] << ";" << endl;
            }
        }
       
    }
    ~Errors()
    {
        value.clear();
        valuename.clear();
    }
};
istream& operator >>(istream& istr, Force &f)
{
    istr >> f.F[0] >> f.F[1] >> f.F[2];
    return istr;
}


int main()
{
    // силу F1 вводим с клавиатуры, силы F2,F3 определяем через конструктор при известных значениях x,y,z;
    char x[20];
    char y[20];
    char z[20];
    cout << "Input F1: " << endl;
    Force F1;
    cin >> F1;
    cout << "F1" << F1 << endl;

    double Module = F1.Magnitude();
    cout << "Magnitude: " << Module << endl << endl;
    cout << "Input F2: " << endl;
    try
    {
        getchar();
        scanf("%s", &x);
        scanf("%s", &y);
        scanf("%s", &z);
        if (!atoi(x) || !atoi(y) || !atoi(z))
        {
            throw Errors('x', x, 'y', y, 'z', z);
        }

    }
    catch (Errors errObj)
    {
        cout << "Error input:" << endl;
        errObj.print_value();
        errObj.~Errors();
        system("pause");
        return 1;
    }
    
    Force F2(atoi(x),atoi(y),atoi(z)), F3(4, 0, 0);
    cout << "F2" << F2 << "F3" << F3 << endl;
    cout << "F2 + F3: " << F2 + F3 << endl;
    cout << "Magnitude: " << (F2 + F3).Magnitude() << endl << endl;
    cout << "F2 - F3: " << F2 - F3 << endl;
    cout << "Magnitude: " << (F2 - F3).Magnitude() << endl << endl;

    int a, b;
    cout << "Input a: ";
    cin >> a;
    cout << "F1 * a: " << F1*a << endl;
    cout << "Input b: ";
    cin >> b;
    cout << "F2 * b: " << F2*b << endl;


    system("pause");
    return 0;
}
