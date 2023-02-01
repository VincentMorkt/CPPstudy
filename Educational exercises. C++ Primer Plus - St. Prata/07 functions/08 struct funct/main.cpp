// Вернитесь к программе из листинга 7.15, не использующей класс array. Напишите следующие две версии.
// а. Используйте обычный массив из const char * для строковых представлений
// времен года и обычный массив из douЫe для расходов.
// б. Используйте обычный массив из const char * для строковых представлений времен года и структуру, единственный член которой является обычным
// массивом из double для расходов. (Это очень похоже на базовое проектное решение для класса array.)

// arrobj.cpp -- functions with array objects
#include <iostream>
struct expens
{
    double x;
};

const int Seasons = 4;
const char *Snames[Seasons] =
    {"Spring", "Summer", "Fall", "Winter"};

void fill(expens pa[Seasons]);
void show(const expens da[Seasons]);
int main()
{
    expens expenses [Seasons];
    fill(expenses);
    show(expenses);
    std::cin.get();
    std::cin.get();
    return 0;
}

void fill(expens pa[Seasons])
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i].x;
    }
}

void show(const expens da[Seasons])
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i].x << '\n';
        total += da[i].x;
    }
    std::cout << "Total: $" << total << '\n';
}
