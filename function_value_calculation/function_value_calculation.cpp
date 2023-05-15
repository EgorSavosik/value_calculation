#include <iostream>

using namespace std;

const double EPS = 0.01;


double f(double x)
{
    return 7 * pow(sin(x), 2);
}

double solveMethod(double a, double b)
{
    double x1 = (a + b - EPS) / 2;
    double x2 = (a + b + EPS) / 2;

    double y1 = f(x1);
    double y2 = f(x2);
    if (y1 > y2)
    {
        a = x1;
    }
    else
    {
        b = x2;
    }

    if (b - a > 2 * EPS)
    {
        solveMethod(a, b);
    }
    else
    {
        double Xmin = (a + b) / 2;
        return Xmin;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");

    double a;
    double b;

    cout << "\t \t \t Методом деления отрезка пополам найти минимум фукнции на отрезке [a,b] \n";
    cout << "Пример функции f(x): 7sin^2(x) \n \n";

    cout << "Введите координаты точек a,b \n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    double Xmin = solveMethod(a, b);
    cout << "Минимум функции x = " << Xmin << "\n";
    cout << "f(x) = " << f(Xmin) << "\n \n";
}