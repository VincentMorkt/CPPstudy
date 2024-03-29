// 2. Решите задачу из упражнения 1, но учтите такие нюансы, как прописные и
// строчные буквы, пробелы и знаки препинания. То есть строка "Madam, I'm Adam"
// должна быть признана палиндромом. Например, функция проверки могла бы
// уменьшить строку до "madamimadam", а затем проверить, эквивалентна ли ей
// строка в обратном порядке. Не забудьте об удобной библиотеке cctype. В ней
// можно найти несколько подходящих функций STL, хотя это и не обязательно.

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
    cout << "enter your word or frase<q to quit>: ";
    string word;
    getline(cin, word);
    while (!(tolower(word[0]) == 'q' && word[1] == '\0'))
    {
        if (word.size() == 0)
        {
            cout << "I SAY ENTER SOMETHING MOTHERFUCKER<q to quit>: ";
            getline(cin, word);
            continue;
        }

        if (palindrom(word))
            cout << "It's palindrom! TENET, YOU UNDERSTAND?\?!\n\n";
        else
            cout << "so boooring\n\n";
        cout << "enter your word <q to quit>: ";
        getline(cin, word);
    }
    return 0;
}

bool palindrom(std::string str)
{

    int i = 0;
    while (i < str.size())
    {
        if (!isalpha(str[i]))
        {
            str.erase(i, 1);
            continue;
        }
        i++; // инкремент нужен только при неизменной строке. При удалении символа место str[i] займёт следующий символ, который нуждается в проверке
    }
    i = 0;
    int size = str.size();
    if (size == 0)
        return 0;
    for (i; i < --size; i++) // --size - последний символ строки, каждая следующая проверка требует переход к предыдущему символу
    {
        if (tolower(str[i]) != tolower(str[size]))
            return false;
    }
    return true;
}