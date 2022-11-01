#include <iostream>
double calculate(double x, double y, double (*operation)(double x, double y)); // прототипы функций
double add(double x, double y);
double sub(double x, double y);
double mult(double x, double y);
double div(double x, double y);

int main()
{
    const int Num = 4;                                                   // константа управления размерами массивов
    double (*arrFunct[Num])(double x, double y) = {add, sub, mult, div}; // массив указателей на функции, инициализированный адрессами функций (их именами)
    const char namesOperation[Num] = {'+', '-', '*', '/'};               // массив символов операций для красоты
    double x, y;                                                         // объявление переменных
    std::cout << "Enter two values: ";                                   // приглошение для ввода значений
    while (std::cin >> x >> y)
    {                                 // цикл продолжается, пока ввод значений успешн. Ввод символа, который невозможно трактовать как часть значения с плавающей точкой прервёт выполнение программы.
        for (int i = 0; i < Num; i++) // вложеный цикл вызывает функцию calculate(), поочерёдно передавая ей значения адрессов функций из массива указателей на функции
        {
            std::cout << x << ' ' << namesOperation[i] << ' ' << y << " = " << calculate(x, y, *arrFunct[i]) << std::endl;
        }
        std::cout << "Enter two values: "; // приглашение для повторного ввода значений
    }
    // завершение роботы программы после ввода нечислового значения
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
    std::cout << "You input a letter. Program closing...";
    std::cin.get();
}

double calculate(double x, double y, double (*operation)(double x, double y)) // функция возвращает double и принимает два значения double и указатель на функцию,
{                                                                             // принимающую два значения double, и возвращающую double.
    return operation(x, y);
}

double add(double x, double y)  // функции арифметических операций
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double mult(double x, double y)
{
    return x * y;
}

double div(double x, double y)
{
    return x / y;
}