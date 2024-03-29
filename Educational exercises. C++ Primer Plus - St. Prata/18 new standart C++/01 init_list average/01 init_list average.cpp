// 1. Ниже показана часть короткой программы:
#include <iostream>
#include <initializer_list>
template <typename T>
T average_list(std::initializer_list<T> list)
{
    T tot = 0;
    int count = 0;
    for (auto p = list.begin(); p != list.end(); p++)
    {
        tot += *p;
        count++;
    }
    return tot / count;
}

int main()
{
    using namespace std;
    // Список double выведен из содержимого списка
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
    // Список int выведен из содержиw.ого списка
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
    // Принудительное исполь зование списка double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    cin.get();
    return 0;
}
// Завершите программу, написав функцию average_list(). Она должна быть
// шаблонной функцией, с параметром типа, который используется для указания
// вида шаблона initialized_list, применяемого в качестве параметра функции,
// а также для указания возвращаемого типа функции.