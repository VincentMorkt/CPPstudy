/*Напишите программу, которая приглашает пользователя ввести три результата забега на 40 ярдов (или 40 метров, если желаете) и затем отображает эти
значения и их среднее. Для хранения данных применяйте объект array.*/
#include <iostream>
#include <array> // необходимый заголовочный файл
int main()
{
    using namespace std;
    array<double, 3> timeRace; // объявление объекта array
    cout << "Enter 40 yard races results in seconds: \n";
    cout << "Enter first race result: ";
    cin >> timeRace[0]; // обращение к объекту array происходит как и к обычному массиву
    cout << "Enter second race result: ";
    cin >> timeRace[1];
    cout << "Enter third race result: ";
    cin >> timeRace[2];
    cin.get();
    cout << endl
         << "First race time: " << timeRace[0] << endl
         << "Second race time: " << timeRace[1] << endl
         << "Third race time: " << timeRace[2] << endl
         << "Average time: " << (timeRace[0] + timeRace[1] + timeRace[2]) / 3;
    cin.get();
    return 0;
}