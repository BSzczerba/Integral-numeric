#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double* CosFun(double Beginning, double End,int Precision)
{
    int b = 0;
    int a = (End - Beginning) * Precision;
    double* tab = new double[a];
    for (double i = 0; i < End - Beginning; i = i + (1.0/Precision))
    {
        tab[b] = cos(Beginning + i);
        b++;
    }
    return tab;
}

double Integral(double Beginning, double End,int Precision, double* (graph)(double, double,int))
{
    double* tab, number = 0;
    tab = graph(Beginning, End, Precision);
    for (int i = 0; i < (End - Beginning) * Precision; i++)
    {
        number = number + tab[i] * (1.0 / Precision);
    }

    return number;
}

int main()
{
    double End, Beginning, Result;
    int Precision;
    cout << "Give the lower limit of the integral ";
    cin >> Beginning;
    cout << "Give the upper limit of the integral ";
    cin >> End;
    cout << "Specify the precision ";
    cin >> Precision;
    Result = Integral(Beginning, End,Precision,CosFun);
    cout << "The integral value is " << Result;
}