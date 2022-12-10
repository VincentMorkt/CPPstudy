// main.cpp -- тестирование классов Port и VintagePort

#include <iostream>
#include "port.h"

void showPortArr(Port *p[], int size, bool mode = 0);

const int SIZE = 4;

int main()
{
    using std::cout;
    using std::endl;

    Port port1;
    Port port2("Villa Krime", "tawny", 85);
    VintagePort vp1;
    VintagePort vp2("Alushta", "bloody", 120, "The Revenge", 2023);

    Port *portArr[SIZE] = {&port1, &port2, &vp1, &vp2}; // массив указателей на базовый класс
    showPortArr(portArr, SIZE);
       
    Port temp("Port temp", "ruby", 1);
    port1 = port2;
    port1 += 100;
    vp1 = port2 = temp;
    vp1 += 55;

    showPortArr(portArr, SIZE, 1);

    cin.get();
    return 0;
}

void showPortArr(Port *p[], int size, bool mode)
{
    using std::cout;
    using std::endl;
    if (mode == 0)
        for (int i = 0; i < size; i++)
        {
            p[i]->Show();
            cout << endl;
        }
    else
        for (int i = 0; i < size; i++)
        {
            cout << *p[i] << endl;
        }
}