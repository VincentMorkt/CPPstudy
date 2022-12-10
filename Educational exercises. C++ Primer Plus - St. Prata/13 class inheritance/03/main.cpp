// 3. Перепишите иерархию классов baseDMA-lacksDMA-hasDMA таким образом, чтобы все три класса были порождены от абстрактного базового класса.
// Протестируйте результат с помощью программы, подобной приведенной в листинге 13.10. То есть она должна использовать массив указателей
// на абстрактный базовый класс и позволять пользователю принимать во время работы программы решения о том, объекты какого типа создавать.
// Добавьте в определения классов виртуальные методы View() для управления выводом данных.

#include <iostream>
#include <string>
#include <cstring>
#include "dma.h"

const int SIZE = 4;

int main()
{
    using namespace std;
    absDMA *dimas[SIZE];
    char choice;

    cout << "b: base DMA, l: lacks DMA\n"
         << "h: has DMA,  q: quit\n"
         << "Enter yuor choice: ";
    int i = 0;
    while (i < SIZE)

    {
        cin >> choice;
        if (strchr("blhqBLHQ", choice) == NULL)
        {
            cout << "Bad input, try again: ";
            if (choice != '\n')
                while (cin.get() != '\n')
                    continue;
            continue;
        }
        while (cin.get() != '\n')
            continue;
        if (toupper(choice) == 'Q')
            break;
        switch (choice)
        {
        case 'B':
        case 'b':
        {
            dimas[i] = new baseDMA;
            cin >> (baseDMA &)*dimas[i];
            break;
        }

        case 'l':
        case 'L':
        {
            dimas[i] = new lacksDMA;
            cin >> (lacksDMA &)*dimas[i];
            break;
        }
        case 'h':
        case 'H':
        {
            dimas[i] = new hasDMA;
            cin >> (hasDMA &)*dimas[i];
            break;
        }

        default:
            break;
        }
        i++;
        cout << "b: base DMA, l: lacks DMA\n"
             << "h: has DMA,  q: quit\n"
             << "Enter yuor choice: ";
    }

    cout << "\n";
    for (int j = 0; j < i; j++)
    {
        dimas[j]->View();
        cout << endl;
    }

    cin.get();
    return 0;
}