#include "golf.h"
#include <cstring>
#include <iostream>

// Неинтерактивная версия:
// функция присваивает структуре типа golf имя игрока и его гандикап (фору), используя передаваемые ей аргументы
void setgolf(golf &g, const char *name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}
// Интерактивная версия:
// функция предлагает пользователю ввести имя и гандикап, присваивает элементам структуры g введенные значения;
// возвращает 1, если введено имя, и 0, если введена пустая строка
int setgolf(golf &g)
{
    using std::cin;
    using std::cout;
    cout << "Enter name: ";    // введите имя
    cin.get(g.fullname, Len);  // ввод строки в член структуры fullname
    if (g.fullname[0] == '\0') // если первый символ имени - нулевой (введена пустая строка)
    {
        ClearIStream();
        return 0; // вернуть 0;
    }
    ClearIStream();             // очистка ввода (если введено более Len - 1 символов)
    cout << "Enter handicap: "; // введите гендикап
    while (!(cin >> g.handicap))  // цикл ввода. Если НЕ ввод числа в член структуры handicap был успешн
    {
        cout << "Incorrect input, enter number: "; // некорректный ввод, введите число
        ClearIStream();                            // очистка некорректного ввода
    }
    ClearIStream(); // очистка ввода (если псое числа присутствовали символы)
    cout << std::endl;
    return 1;       // вернуть 1 после успешного ввода числа.
}

// Функция устанавливает новое значение гандикапа
void handicap(golf &g, int hc) { g.handicap = hc; } // простое прямое присвоение

// Функция отобража ет содержимое структуры типа golf
void showgolf(const golf &g)
{
    std::cout << "Name: " << g.fullname << "\t Handicap: " << g.handicap << std::endl;// простое отображение значений
}

void ClearIStream(void) // Функция очистки потока ввода
{
    std::cin.clear();
    while (std::cin.get() != '\n') // цикл очистки потока ввода. считать символ,
        continue;                  // продолжать, пока не встретится символ новой строки
}
