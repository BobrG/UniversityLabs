////11.  Ќаписать класс, реализующий пон€тие јтом.¬ классе должны содержатьс€ :
////
////a.‘ункции определени€ массы атома по количеству протонов и нейтронов
////
////b.‘ункци€, определ€ющие выходные значени€ массы и зар€да атома после јльфа - и Ѕэта - распада.
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

class Complex         // класс " омплексное число"
{
private:
    double re, im;      // действительна€ и мнима€ части

public:
    // конструкторы 

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

    Complex(const Complex &c)   // конструктор копировани€
    {
        re = c.re;
        im = c.im;
    }

    // деструктор
    ~Complex()
    {
    }

    // остальные функции

    // ћодуль комплексного числа
    double abs()
    {
        return sqrt(re * re + im * im);
    }

    // оператор присваивани€
    Complex& operator = (Complex &c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }


    // оператор +=
    Complex& operator += (Complex &c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // оператор сложени€
    Complex operator + (const Complex &c)
    {
        return Complex(re + c.re, im + c.im);
    }

    // оператор вычитани€
    Complex operator - (const Complex &c)
    {
        return Complex(re - c.re, im - c.im);
    }

    // оператор умножени€
    Complex operator * (const Complex &c)
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // оператор делени€
    Complex operator / (const Complex &c)
    {
        Complex temp;

        double r = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / r;
        temp.im = (im * c.re - re * c.im) / r;

        return temp;
    }

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend ostream & operator<< (ostream &, const Complex &);
    friend istream & operator>> (istream &, Complex &);

};

// перегрузка оператора <<
ostream& operator<< (ostream &out, const Complex &c)
{
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}

// перегрузка оператора >>
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