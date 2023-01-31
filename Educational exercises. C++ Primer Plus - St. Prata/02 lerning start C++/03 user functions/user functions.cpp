// 3. Напишите программу на С++, которая использует три определяемых пользователем функции 
// (включая main()) и генерирует следующий вывод:
// Three blind mice
// Three blind mice
// See how they run
// See how they run

#include <iostream>

using namespace std;

void ThreeBlindMice(void) // функция, выводящая на консоль строку "Three blind mice"
{
    cout << "Three blind mice" << endl;
}

void SeeHowTheyRun(void) // аналогичная функция для строки "See how they run"
{
    cout << "See how they run" << endl;
}

int main()
{
    ThreeBlindMice(); // вызов функций в соответствии с заданинм. циклы не используются ни здесь, ни в пользовательских функциях, это материал последующих глав.
    ThreeBlindMice();
    SeeHowTheyRun();
    SeeHowTheyRun();
    cin.get();
    return 0;
}