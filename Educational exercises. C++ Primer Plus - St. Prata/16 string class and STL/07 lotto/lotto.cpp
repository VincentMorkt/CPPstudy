// 7. Лотерея - довольно популярная игра. Карточка лотереи имеет нумерованные
// поля, из которых случайным образом выбирается определенное количество
// номеров. Напишите функцию Lotto(), принимающую два аргумента. Первым
// должно быть число номеров на карточке лотереи, а вторым -
// количество случайным образом выбранных номеров. Функция должна возвращать объект
// vector<int>, содержащий отсортированные по порядку случайно выбранные
// номера. Эту функцию можно использовать, например, так:
// vector<int> winners;
// winners = Lotto(51, 6);
// Этот код присвоил бы объекту winners вектор, содержащий шесть случайным
// образом выбранных номеров в диапазоне от 1 до 51. Обратите внимание, что
// простого использования rand() не достаточно для решения этого упражнения,
// потому что она может генерировать дублированные значения. Совет: пусть
// функция создает вектор, который содержит все возможные значения, затем
// применяйте random_shuffle(), после чего используйте начало перетасованного
// вектора для получения значений. Также напишите короткую программу для
// тестирования разработанной функции.

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
std::vector<int> Lotto(int numbers, int amount);

int main()
{
    cout << "Enter numbers on the ticket <q to quit>: ";
    int numbers;
    while (cin >> numbers)
    {
        cin.get();
        cout << "Enter number of selected: ";
        int selected;
        cin >> selected;
        cin.clear();
        while (cin.get() != '\n')
            continue;
        vector<int> winners;
        winners = Lotto(numbers, selected);
        cout << "\t\t  Winers: ";
        copy(winners.begin(), winners.end(), ostream_iterator<int, char>(cout, " "));
        cout << endl
             << endl;
        cout << "Enter number of numbers on the ticket <q to quit>: ";
    }

    return 0;
}

vector<int> Lotto(int numbers, int amount)
{
    vector<int> nums;
    for (int i = 0; i < numbers; i++)
        nums.insert(nums.end(), i + 1);
    random_shuffle(nums.begin(), nums.end());
    nums.erase(nums.begin() + amount, nums.end());
    return nums;
}