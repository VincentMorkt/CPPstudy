// 6. Напишите программу, в которой функция main() вызывает определяемую пользователем функцию, 
// принимающую в качестве аргумента расстояние в световых годах 
// и возвращающую расстояние в астрономических единицах. Программа должна выдать запрос на ввод 
// значения в световых годах и отобразить следующий результат:
// Enter the number of light years: 4.2
// 4.2 light years = 265608 astronomical units.
// Используйте тип double и следующий коэффициент преобразования:
// 1 световой год = 63 240 астртюмических единиц
#include <iostream>

double LYtoAU(double lightYears);   // прототип функции, принимающей double и возвращающей double

int main() 
{
    using namespace std; 
    cout << "Enter the number of light years: ";
    double lightYears;
    cin >> lightYears;
    cin.get();
    cout << lightYears << " light years = " << LYtoAU(lightYears) << " astronomical units.";
    cin.get();
    return 0;
}

double LYtoAU(double lightYears)
{
    return lightYears * 63240; 
}