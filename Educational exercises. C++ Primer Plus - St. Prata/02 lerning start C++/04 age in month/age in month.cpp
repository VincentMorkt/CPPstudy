// 4. Напишите программу, которая предлагает пользователю ввести свой возраст.
// Затем программа должна отобразить возраст в месяцах:
// Enter your age: 29
// Your age in months is 348.

#include <iostream>

int main()
{
    using namespace std;
    cout << "     Enter your age: ";
    int age;
    cin >> age;
    cin.get();
    cout << "Your age in month is " << age * 12 << endl;
    cin.get();
    return 0;
}