////11.  �������� �����, ����������� ������� ����.� ������ ������ ����������� :
////
////a.������� ����������� ����� ����� �� ���������� �������� � ���������
////
////b.�������, ������������ �������� �������� ����� � ������ ����� ����� ����� - � ���� - �������.
////
//#include <iostream>
//#include <iomanip>
//using namespace std;
//class Atom
//{
//private:
//    int protons, neutrons;
//public:
//    Atom(int neutro, int proto)
//    {
//        Weight();
//    }
//    void Weight(int neutro, int proto)
//    {
//        int weight;
//        weight = (proto + neutro) * 1.67;
//        cout << "Weight: " << weight << " u;" << endl;
//    }
//    void Alfa_decay()
//    {
//
//    }
//    void Betta_decay()
//    {
//
//    }
//};
//main()
//{
//    int protons, neutrons;
//    cout << "Input protons: ";
//    cin >> protons;
//    cout << endl << "Input neutrons: ";
//    cin >> neutrons;
//    Atom Atm(protons, neutrons);
//    system("pause");
//    return 0;
//}
#include <iostream>
#include <cmath>

using namespace std;

class Complex         // ����� "����������� �����"
{
private:
    double re, im;      // �������������� � ������ �����

public:
    // ������������ 

    Complex()
    {
    };

    Complex(double r)
    {
        re = r;
        im = 0;
    }

    Complex(double r, double i)
    {
        re = r;
        im = i;
    }

    Complex(const Complex &c)   // ����������� �����������
    {
        re = c.re;
        im = c.im;
    }

    // ����������
    ~Complex()
    {
    }

    // ��������� �������

    // ������ ������������ �����
    double abs()
    {
        return sqrt(re * re + im * im);
    }

    // �������� ������������
    Complex& operator = (Complex &c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }


    // �������� +=
    Complex& operator += (Complex &c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // �������� ��������
    Complex operator + (const Complex &c)
    {
        return Complex(re + c.re, im + c.im);
    }

    // �������� ���������
    Complex operator - (const Complex &c)
    {
        return Complex(re - c.re, im - c.im);
    }

    // �������� ���������
    Complex operator * (const Complex &c)
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // �������� �������
    Complex operator / (const Complex &c)
    {
        Complex temp;

        double r = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / r;
        temp.im = (im * c.re - re * c.im) / r;

        return temp;
    }

    // ������ ������������� ���������, ������� �� ��������� ������
    // � ������ (private) ������
    friend ostream & operator<< (ostream &, const Complex &);
    friend istream & operator>> (istream &, Complex &);

};

// ���������� ��������� <<
ostream& operator<< (ostream &out, const Complex &c)
{
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}

// ���������� ��������� >>
istream& operator>> (istream &in, Complex &c)
{
    in >> c.re >> c.im;
    return in;
}

int
main()
{
    Complex a(5, 2);
    Complex b(3, -3);

    cout << "a = " << a << "; b =" << b << endl;

    a += b;

    cout << "a = " << a << "; b =" << b << endl;

    Complex c = a + b;

    cout << c << endl;
    cout << a + b << endl;
    cout << a * b << endl;
    system("pause");
    return 0;
}