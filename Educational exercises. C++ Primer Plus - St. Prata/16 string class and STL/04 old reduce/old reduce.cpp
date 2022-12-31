// 4. Напишите функцию с интерфейсом в старом стиле, которая имеет следующий прототип:
// int reduce(long ar[], int n);
// Действительными аргументами должны быть имя массива и количеством элементов в нем.
// Функция должна сортировать массив, удалять дублированные значения и возвращать значение,
// равное числу элементов в уменьшенном массиве.Напишите эту функцию, используя функции STL.
// (Если вы решите применить общую функцию unique(), обратите внимание,
// что она возвращает конец результирующего диапазона.)
// Протестируйте эту функцию в короткой программе.
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cctype>
const int Size = 50;

int reduce(long ar[], int n);

int main()
{
    long arr[Size];
    std::srand(std::time(0));

    for (int i = 0; i < Size; i++)
        arr[i] = std::rand() % 30 + 1;

    for (int i = 0; i < Size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    int resultSize = reduce(arr, Size);

    for (int i = 0; i < resultSize; i++)
        std::cout << arr[i] << " ";

    std::cin.get();

    return 0;
}

int reduce(long ar[], int n) // пузырьковая сортировка
{

    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j < n)
        {
            if (ar[i] == ar[j])
            {
                std::swap(ar[j] = 0, ar[--n]);
                continue;
            }
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - (1 + i); j++)
            if (ar[j] > ar[j + 1])
            {
                std::swap(ar[j], ar[j + 1]);
                flag = false;
            }
        if (flag)
            break;
    }

    return n;
}