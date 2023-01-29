// 3. Напишите и протестируйте шаблонную функцию с переменным числом аргументов sum_values(), 
// которая принимает список произвольной длины с аргументами, имеющими числовые значения (смешанных типов), 
// и возвращает сумму в виде значения long double. 
#include<iostream>

template <typename T>
long double sum_values(const T& t)
{
    return t;
}
template <typename T, typename... Args>
long double sum_values(const T& t, const Args&... args)
{
    return t + sum_values(args...);
}

int main()
{
    using namespace std;
    cout << fixed << sum_values('A', 23.5, 0, 1, true, false, '%', 16.3E12, 012, 0xF);
    cin.get();
}