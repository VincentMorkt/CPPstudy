// 4. Перепишите финальный пример класса Time (листинги 11.10, 11.11 и 11.12) так, чтобы все перегруженные операции были реализованы с использованием дружественных функций.

// main.cpp -- использование метода Time

#include <iostream>
#include "time.h"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    std::cin.get();
    return 0;
}