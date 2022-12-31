// 5. Решите ту же задачу, что и в упражнении 4, но с помощью шаблонной функции:

// Протестируйте функцию в короткой программе, используя экземпляры с long и string.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cctype>

template <typename T>
int reduce(T ar[], int n);

int main()
{   
    int Size = 50;
    long arr[Size];
    std::srand(std::time(0));

    for (int i = 0; i < Size; i++)
        arr[i] = std::rand() % 30 + 1;

    for (int i = 0; i < Size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    Size = reduce(arr, Size);

    for (int i = 0; i < Size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    

    Size = 6;
    std::string sarr[Size] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    for (const auto str : sarr)
        std::cout << str << " ";
    std::cout << std::endl;

    Size = (reduce(sarr, Size));

    for (int i = 0; i < Size; i++)
        std::cout << sarr[i] << " ";


    std::cin.get();

    return 0;
}

template <typename T>
int reduce(T ar[], int n) // пузырьковая сортировка
{
    for (int i = 0; i < n; i++) // удаление всех дублированных значений перед сортировкой
    {
        int j = i + 1;
        while (j < n)
        {
            if (ar[i] == ar[j])
            {
                std::swap(ar[j], ar[--n]); // дублированное значение ставится в конец массива, размер массива уменьшается
                continue;                      // такой способ имеет постоянную сложность
            }
            j++; // инкремент необходим только если не было свапа, иначе нам всё ещё нужно проверить значение с предыдущим индексом
        }
    }

    for (int i = 0; i < n; i++) // пузырьковая сортировка
    {
        bool flag = true;
        for (int j = 0; j < n - (1 + i); j++)
            if (ar[j] > ar[j + 1])
            {
                std::swap(ar[j], ar[j + 1]);
                flag = false;
            }
        if (flag) // если за проход не было ни одной замены - массив отсортирован
            break;
    }

    return n;
}