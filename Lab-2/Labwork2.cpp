#include <iostream>
#include <iomanip>
#include <cmath>

double getSumOfRow(double x, double absError, int numberOfMax); //Прототип функции 

double getRealValue()
{
    double n;
    while (!(std::cin >> n))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Ошибка введено неверное значение! ";
    }
    return abs(n);
}

int main()
{
    setlocale(LC_ALL, "ru");
    double x1, x2;
    double answer;
    int numberOfMax = 0;
    const int XWIDTH = 20;
    const int YWIDTH = 20;
    const double PAS = 0.00000000001;

    std::cout << "Введите интервал" << std::endl;
    std::cout << "Введите x1: ";
    std::cin >> x1;
    std::cout << "Введите x2: ";
    std::cin >> x2;
    std::cout << "Введите шаг: ";
    double step = getRealValue();
    
    std::cout << "Введите точность: ";
    double absError = getRealValue(); // Абсолютная погрешность
    std::cout << "Введите максимальное количество слагаемых: ";
    std::cin >> numberOfMax; // Номер слагаемого суммы 
    std::cout << std::setw(XWIDTH) << "x" << std::setw(YWIDTH) << "y" << '\n'; // setw - манипулятор ширины

    for (double x = x1; x <= x2; x += step) 
    {
        if (x > 0 - PAS && x < 0 + PAS) // Обходит ноль
        {
            continue;
        }
        answer = getSumOfRow(x, absError, numberOfMax);
        std::cout << std::setw(XWIDTH) << x << std::setw(YWIDTH) << answer << std::setw(40) << 1 / exp(x) << '\n';
    } 
    return 0;
}

double getSumOfRow(double x, double absError, int numberOfMax) 
{
    double sum = 0;
    double y = 1;
    int count = 0;
    sum += y;
    while (abs(y) > absError) 
    {
        if (count == numberOfMax)
        {
            break;
        }
        count++;
        y = y * (-1) * x / count;
        sum += y;
    }
    return sum;
}
