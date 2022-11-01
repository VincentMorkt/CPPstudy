// 5. Напишите программу, в которой функция main() вызывает определяемую пользователем функцию,
// принимающую в качестве аргумента значение температуры по Цельсию и возвращающую эквивалентное значение температуры по Фаренгейту.
// Программа должна выдать запрос на ввод значения по Цельсию и отобразить следующий результат:
// Please enter а Celsius value: 20
// 20 degrees Celsius is 68 degrees Fahrenheit.

// Вот формула для этого преобразования:
// Температура в градусах по Фаренгейту = 1,8 * Температура в градусах по Целъсисию + 32

#include <iostream>

int CelsiusToFahrenheit(int deg); // прототип функции

int main()
{
    using namespace std;
    cout << "Please enter a Celsius value: ";
    int degrees;
    cin >> degrees; // ввод значения с консоли
    cin.get();
    cout << degrees << " degrees Celsius is " << CelsiusToFahrenheit(degrees) << " degrees Fahrenheit." << endl; // объект cout выводит в консоль возврат вызова функции
    cin.get();                                                                                                   // с передачей ей значения переменной
    return 0;
}

int CelsiusToFahrenheit(int deg) // определение функции (принимает int, возвращает int)
{
    return 1.8 * deg + 32; // оператор возврата, возвращает результат выражения в соответствии с ТЗ
}
