// ре 14-1 . срр - класс Wine с использованием закрытого наследования
#include <iostream>
#include "wine.h"

int main(void)
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    // ввод названия вина
    cout << "Enter number of years: ";
    int yrs;
    // ввод количества годов сбора винограда
    cin >> yrs;
    Wine holding(lab, yrs); // сохранение названия, лет, соэдание массивов из yrs элементов
    holding.GetBottles();   // предложение ввести год и количество бутылок
    cout << endl;
    holding.Show();                                  // вывод содержимого объекта
    cout << "Total bot tles for " << holding.Label() // исполь зуется метод Label ()
         << ": " << holding.sum() << endl;           // используется метод sum ()
    cout << endl;
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    // Создание нового объекта, инициализация с исполь зо6анием данных из масси6О6 y и b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bot tles for " << more.Label() // исполь зуется метод Label ()
         << ": " << more.sum() << endl;           // используется метод sum ()
    cout << endl;
    cout << "Bye\n";
    cin.get();
    return 0;
}