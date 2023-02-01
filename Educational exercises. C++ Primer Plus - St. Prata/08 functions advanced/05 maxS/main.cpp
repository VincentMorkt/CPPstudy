// Напишите шаблонную функцию maxS(), которая принимает в качестве аргумента массив из пяти элементов типа T и возвращает наибольший элемент в массиве.
// (Поскольку размер массива фиксирован, его можно жестко закодировать в цикле, а не передавать в виде аргумента.)
// Протестируйте функцию в программе с использованием массива из пяти значений int и массива из пяти значений double.
#include <iostream>

template <typename T>
T maxS(const T arr[]);    // Шаблонная функция, находящая максимальное значение массива фиксированного размера
int arrSize = 5;

int main()
{
    using namespace std;
    int intArr[arrSize] = {1, 5, 2, 4, 3};
    double doubleArr[arrSize] = {1.1, 5.5, 2.2, 4.4, 3.3};
    cout << maxS(intArr) << endl
         << maxS(doubleArr) << endl;
    cin.get();
    return 0;
}

template <typename T>
T maxS(const T arr[])
{
    T temp = arr[0];
    for (int i = 1; i < arrSize; i++)
        temp = (temp > arr[i]) ? temp : arr[i];
    return temp;
}