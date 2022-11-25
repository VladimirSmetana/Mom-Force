#include "pch.h"
#include <iostream>
#include <math.h>
using namespace System;
using namespace std;

int main()
{
    // Объявление констант
    const double PI = 3.141592653589793; // число "пи"
    const double g = 9.81; // ускорение свободного падения
    const double B = 30; // угол полураствора конуса ГО
    const double p = 0.4; // плотность воздуха
    const double V = 600; // скорость РКН
    const double u = 90; // скорость ветра

    // Объявление вводимых переменных
    double lo, D, mass, nx;

    // Объявление рассчитываемых переменных
    double q;
    double a;
    double Xa;
    double Ya;
    double N;
    double M;
    double Np;
    double pn;

    // Запрос на ввод длины отсекаемой части РКН
    cout << "Input lo, m" << "           lo = ";
    cin >> lo; 
    // Запрос на ввод максимального диаметра РКН
    cout << "Input D, m" << "             D = ";
    cin >> D;
    // Запрос на ввод максимального диаметра РКН
    cout << "Input mass, kg" << "         mass = ";
    cin >> mass;
    // Запрос на ввод массы отсеченной части РКН
    cout << "Input nx" << "               nx = ";
    cin >> nx;

    cout << endl;

    // Определение максимального скоростного напора
    q = (p * pow(V,2)) / 2;
    // Расчет эффективного угла атаки
    a = u / V;
    // Расчет аэродинамической силы сопротивления X_a
    Xa = 2 * pow(30 * PI / 180,2) * q * (PI * pow(D,2)) / 4;
    // Расчет аэродинамической подъемной силы Y_a
    Ya = 3 * a * q * (PI * pow(D, 2)) / 4;
    // Определение продольной силы, действующей в сечении
    N = -Xa - mass * nx * g;
    // Расчет изгибающего момента в сечении
    M = Ya * lo * (1 - lo / (2 * lo));
    // Расчёт приведенной сжимающей силы
    Np = N + 4 * M / D;
    // Расчёт давления наддува баков
    pn = 4 * Np / (PI * pow(D, 2));

    // Вывод итоговых значение изгибающего момента, сжимающей силы и давления наддува баков
    cout << "M= " << M << " Hm\n";
    cout << "N = " << Np << " H\n";
    cout <<"pn= " << pn << " Pa\n";

    return 0;
}
