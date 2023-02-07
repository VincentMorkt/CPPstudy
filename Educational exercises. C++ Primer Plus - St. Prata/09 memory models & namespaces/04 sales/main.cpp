#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    using namespace std;
    Sales var[2];
    cout << "Uninteractive funct:\n";
    double values[QUARTERS] = { 3.2,
                                5.4,
                                1.1,
                                0.2 };
    setSales(var[0], values, QUARTERS);
    showSales(var[0]);

    cout << "Interactive funct:\n";
    setSales(var[1]);
    showSales(var[1]);
    cin.get();

    return 0;
}