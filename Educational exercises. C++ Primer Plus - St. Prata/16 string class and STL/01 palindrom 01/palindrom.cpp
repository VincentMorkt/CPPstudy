// 1. Палииндром - это строка, которая читается одинаково в обоих направлениях.
// Например, "tot" и "otto" - короткие палиндромы. Напишите программу, которая
// запрашивает у пользователя строку и передает ссылку на нее функции
// bool. Функция должна возвращать true, если строка является палиндромом,
// и false - в противном случае. Пока не беспокойтесь о таких нюансах,
// как прописные и строчные буквы, пробелы и знаки препинания. Другими словами,
// эта простая версия должна отклонять строки типа "Otto" и "Madam, I'm Adam". Для
// упрощения решения задачи можете обратиться к списку строковых методов,
// приведенному в приложении Е.

#include <iostream>
#include <cstring>
#include <string>

bool palindrom(std::string str);
int main()
{
    using namespace std;
    cout << "enter your word<q to quit>: ";
    string word;
    cin >> word;
    while (!(tolower(word[0]) == 'q' && word[1] == '\0'))
    {
        if (word.size() == 0)
        {
            cout << "I SAY ENTER SOMETHING MOTHERFUCKER<q to quit>: ";
            cin >> word;
            continue;
        }
        if (palindrom(word))
            cout << "It's palindrom! TENET, YOU UNDERSTAND?\?!\n\n";
        else
            cout << "so boooring\n\n";
        cout << "enter your word <q to quit>: ";
        cin >> word;
    }
    return 0;
}

bool palindrom(std::string str)
{
    int size = str.size();
    int i = 0;
    while (i < --size)
    {
        if (tolower(str[i]) != tolower(str[size]))
            return false;
        else
            i++;
    }
    return true;
}