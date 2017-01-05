//многочлен -- 2 вектора. Один для коэфф-тов, один для степеней;
#include <iostream>
#include <vector>
using namespace std;

class Polynom
{
private:
    vector <int> polyk;
    vector <int> polye;
public:
    //конструктор;
    Polynom(int n)
    {
        polyk.resize(n);
        polye.resize(n);
    }
    Polynom()
    {
        int n, m;
        cout << "Input n: ";
        cin >> n;
        cout << endl;
        polyk.resize(n);
        polye.resize(n);
        for (int i = 0; i < n; i++)
        {
            printf("Input koeff.%d: ", i + 1);
            cin >> polyk[i];
            printf("Input exp.%d: ", i + 1);
            cin >> polye[i];

        }
        m = n;
        for (int i = 0; i < n; i++)
        {
            if (polyk[i] == 0)
            {
                polyk.erase(polyk.begin() + i);
                polye.erase(polye.begin() + i);
                m = n--;
            }
        }
        if (m < n)
        {
            polyk.resize(m);
            polye.resize(m);
        }
        Summing();
    }
    //сложение многочленов;
    Polynom operator +(Polynom &Plnm)
    {
        int n = polyk.size();
        int m = Plnm.polyk.size();
        Polynom temp(n + m);

        temp.polye = polye;
        temp.polyk = polyk;

        for (int i = 0; i < m; i++)
        {
            temp.polye.emplace_back(Plnm.polye[i]);
            temp.polyk.emplace_back(Plnm.polyk[i]);

        }
        temp.Summing();
        temp.Sort();
        return temp;
    }
    //разность многочленов;
    Polynom operator -(Polynom &Plnm)
    {
        int n = polyk.size();
        int m = Plnm.polyk.size();
        Polynom temp(n + m);

        temp.polye = polye;
        temp.polyk = polyk;

        for (int i = 0; i < m; i++)
        {
            temp.polye.emplace_back(Plnm.polye[i]);
            temp.polyk.emplace_back(-1 * Plnm.polyk[i]);
        }
        temp.Summing();
        temp.Sort();
        return temp;
    }
    //умножение многочлена на многочлен;
    Polynom operator *(Polynom &Plnm)
    {
        int n = polyk.size();
        int m = Plnm.polyk.size();
        Polynom temp(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp.polye.emplace_back(polye[i] + Plnm.polye[j]);
                temp.polyk.emplace_back(polyk[i] * Plnm.polyk[j]);
            }
        }
        for (int i = 0; i < temp.polye.size(); i++)
        {
            for (int j = i + 1; j < temp.polye.size(); j++)
            {
                if (temp.polye[i] == temp.polye[j])
                {
                    temp.polyk[i] += temp.polyk[j];
                    temp.polye.erase(temp.polye.begin() + j);
                    temp.polyk.erase(temp.polyk.begin() + j);
                }
            }
        }
        temp.Sort();
        return temp;
    }
    //умножение многочлена на число;
    Polynom operator *(int a)
    {
        int n = polye.size();
        Polynom temp(n);

        temp.polye = polye;

        for (int i = 0; i < n; i++)
        {
            temp.polyk[i] = a*polyk[i];
        }

        return temp;
    }
    //сортировка многочлена по возрастанию степеней;
    void Sort()
    {
        int vedro = 0;
        for (int i = 0; i < polye.size(); i++)
        {
            for (int j = 0; j < polye.size() - 1; j++)
            {
                if (polye[j] > polye[j + 1])
                {
                    vedro = polye[j + 1];
                    polye[j + 1] = polye[j];
                    polye[j] = vedro;
                    vedro = polyk[j + 1];
                    polyk[j + 1] = polyk[j];
                    polyk[j] = vedro;
                }
            }
        }
    }
    //приведение подобных;
    void Summing()
    {
        for (int i = 0; i < polye.size(); i++)
        {
            for (int j = i + 1; j < polye.size(); j++)
            {
                if (polye[i] == polye[j])
                {
                    polyk[i] += polyk[j];
                    polye.erase(polye.begin() + j);
                    polyk.erase(polyk.begin() + j);
                    j--;
                }
            }
        }
    }
    //возврат размерности полинома;
    int size()
    {
        return polye.size();
    }
    friend ostream& operator <<(ostream& ostr, const Polynom &Plnm);
    ~Polynom()
    {
        polye.clear();
        polyk.clear();
    }
};
ostream& operator <<(ostream& ostr, const Polynom &Plnm)
{
    for (int i = 0; i < Plnm.polye.size(); i++)
    {
        if (Plnm.polyk[i] != 0)
        {
            if (Plnm.polye[i] != 0)
            {
                printf("%dX^%d", Plnm.polyk[i], Plnm.polye[i]);
            }
            else
            {
                printf("%d", Plnm.polyk[i]);
            }
            if (i < Plnm.polye.size() - 1)
            {
                if (Plnm.polyk[i + 1] > 0)
                    printf("+");
            }
        }
    }
    printf("\n\n");
    return ostr;
}
int main()
{
    //определение многочлена p1;
    Polynom p1;
    p1.Sort();
    // p1.Summing();
    cout << p1;
    //определение многочлена p2;
    Polynom p2;
    p2.Sort();
    // p1.Summing();
    cout << p2;

    int z = p1.size() + p2.size();
    Polynom p3(z);
    //сложение многочленов p1 и p2;
    p3 = p1 + p2;
    cout << "Summ: ";
    cout << p3;
    //разность многочленов p1 и p2;
    p3 = p1 - p2;
    cout << "Diff: ";
    cout << p3;
    //умножение многочленов p1 и p2 на числа a и b;
    int a, b;
    printf("Input a: ");
    cin >> a;
    p3 = p1*a;
    cout << "Multiplication P1*a: ";
    cout << p3;

    printf("Input b: ");
    cin >> b;
    p3 = p2*b;
    cout << "Multiplication P2*b: ";
    cout << p3;
    //умножение многочлена p1 на многочлен p2ж
    p3 = p1*p2;
    cout << "Multiplication of polynomials P1 and P2:";
    cout << p3;
    //уничтожение полиномов p1,p2,p3;
    p1.~Polynom();
    p2.~Polynom();
    p3.~Polynom();
    system("pause");
}