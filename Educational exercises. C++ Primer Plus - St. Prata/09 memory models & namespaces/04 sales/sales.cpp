#include "sales.h"
#include <iostream>

// Копирует меньшее значение из 4 или n элементов из массива ar в член sales структуры s,
// вычисляет и сохраняет среднее арифметическое, максимальное и минимальное значения введенных чисел;
// оставшиеся элементы sales, если таковые есть, устанавливаются в 0
namespace SALES
{
    using std::cin; // объявления using
    using std::cout;
    using std::endl;

    void setSales(Sales &s, const double ar[], int n)
    {
        s.average = ar[0]; // переменным-членам структуры присваивается значение нулевого элемента массива
        s.max = ar[0];
        s.min = ar[0];
        for (int i = 0; i < n; i++)
            s.sales[i] = ar[i]; // каждый проход цикла присваивает значения из массива переданного через аргумент в массив член-структуры
        for (int i = 1; i < n; i++)
        {
            s.max = (s.max > ar[i]) ? s.max : ar[i]; // значение нулевого элемента массива, присовенное ранее, сравнивается с другими значениями
            s.min = (s.min < ar[i]) ? s.min : ar[i]; // и при необходимости заменяется на новое
            s.average += ar[i];                      // в этот член структуры записывается сумма всех элементов массива
        }
        s.average /= n; // и после завершения цикла находится их среднее значение путём деления суммы на количество
    }

    // Интерактивно подсчитывает продажи за 4 квартала, сохраняет их в члене sales структуры s,
    // вычисляет и сохраняет среднее арифметическое, а также максимальное и минимальное значения введенных чисел
    void setSales(Sales &s)
    {
        cout << "Enter sales:\n";
        double ar[QUARTERS];
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << i + 1 << " quarter: ";
            cin >> ar[i];
            cin.get();
        }
        setSales(s, ar, QUARTERS);
    }

    // Отображает всю информацию из структуры s
    void showSales(const Sales &s)
    {
        cout << "---showSales()---\n";        
        for (int i = 0; i < QUARTERS; i++)
            cout << i + 1 << " quarter: " << s.sales[i] << endl;
        cout << "Average: " << s.average << endl
             << "    Max: " << s.max << endl
             << "    Min: " << s.min << endl;
    }
}