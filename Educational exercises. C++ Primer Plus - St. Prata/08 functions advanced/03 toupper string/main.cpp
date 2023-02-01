// 3. Напишите функцию, которая принимает ссылку на объект string в качестве параметра и преобразует содержимое string в символы верхнего регистра.
// Используйте функцию toupper(), описанную в табл. 6.4 (см. главу 6). Напишите программу, использующую цикл, которая позволяет проверить работу функции
// для разного ввода. Пример вывода может выглядеть следующим образом:
// Enter a string (q to quit): go away
// GO AWAY
// Next string (q to quit): good grief!
// GOOD GRIEF!
// Next string(q to quit): q
// Вуе.
#include <iostream> // я обнаружил, что программа работает без заголовчных файлов <string> и <cctype>
using namespace std;
void StringToUpper(string &str); // функция, переводящая все буквенные символы строки string в верхний регистр

int main()
{
    string str;
    cout << "Enter a string (q to quit): "; // "Введите строку (q для выхода)"
    while (getline(cin, str) && str != "q") // пока ввод успешн и не равен "q"
    {
        StringToUpper(str);                     // вызов функции
        cout << str << endl;                    // вывод строки
        cout << "Enter a string (q to quit): "; // "Введите строку (q для выхода)"
    }
    cout << "Bye."; // завершение работы
    cin.get();
    return 0;
}

void StringToUpper(string &str)
{
    int lenght = str.length();       // определение длины строки
    for (int i = 0; i < lenght; i++) // цикл посимвольной обработки строки
        str[i] = toupper(str[i]);    // использование функции toupper
}