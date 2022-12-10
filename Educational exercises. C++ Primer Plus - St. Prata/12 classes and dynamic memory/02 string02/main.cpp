// 2. Усовершенствуйте объявление класса String(т.е. замените stringl.h на string2.h), выполнив перечисленные ниже действия.

// а. Перегрузите операцию + для объединения двух строк в одну.
// б. Напишите функцию-член stringlow(), которая преобразует все буквенныеc имволы в строке в нижний регистр. (Не забудьте о семействе cctype символьных функций.)
// в. Напишите функцию-член stringup(), которая преобразует все буквенные символы в строке в верхний регистр.
// г. Напишите функцию-член, которая принимает аргумент типа char и возвращает количество раз, которое символ появляется в строке.

// Проверьте работу полученного класса в следующей программе:

#include <iostream>
#include "string2.h"
using namespace std;

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter yor name: "; // ввод имени
    String s3;
    cout << s2;              // перегруженная операция <<
    cin >> s3;               // перегруженная операция >>
    s2 = "My name is " + s3; // перегруженные операции =, +
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); // преобразование строки в верхний регистр
    cout << "The string\n"
         << s2 << " \ncontains " << s2.has('A')
         << " 'A' characters init.\n";
    s1 = "red"; // String (const char *), тогда String & operator=(const String&)
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: "; // ввод цвета
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // преобразование строки в нижний регистр
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // перегруженная операция ==
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    cin.get();
    return 0;
}

// Вывод программы должен выглядеть приблизительно так:

// Please enter your name: Fretta Farbo
// Му name is Fretta Farbo.
// Тhе string
// МУ NAME IS FRETTA FARBO AND I АМ А С++ STUDENT.
// conta ins 6 'А' characters in it.
// Enter the name of а primary color for mixing light: yellow
// Try again!
// BLUE
// That's right!
// Bуе