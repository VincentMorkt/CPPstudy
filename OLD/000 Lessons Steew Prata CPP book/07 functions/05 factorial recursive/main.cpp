// Определите рекурсивную функцию, принимающую целый аргумент и возвращающу19 его факториал. Вспомните , что факториал 3 записывается, как 3! и
// вычисляется как 3 х 2! и т.д. , причем О! равно 1. В общем случае , если n больше
// нуля, то n! = n * (n - 1)! . Протестируйте функцию в программе, использующей
// цикл, где пользователь может вводить различные значения, для которых программа вычисляет и отображает факториалы.
#include <iostream>
#include <iomanip>
long double factorial(int num);
int main()
{
    int factorialValue = 0;
    while (true)
    {
        std::cout << "Enter a cout to find factorial: ";
        std::cin >> factorialValue;
        if (std::cin)
            std::cin.get();
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input! Enter integer.\n";
            continue;
        }
        std::cout << std::fixed <<std::setprecision(0);
        std::cout << factorialValue << "! = " << factorial(factorialValue) <<std::endl;
    }
    return 0;
}
long double factorial(int num)
{
    if (num > 0)
        return num * factorial(--num);
    else
        return 1;
}