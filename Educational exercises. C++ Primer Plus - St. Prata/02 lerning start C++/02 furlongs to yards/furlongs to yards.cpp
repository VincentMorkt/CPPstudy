// 2. Напишите программу на С++, которая выдает запрос на ввод расстояния в фарлонгах и преобразует его в ярды 
// (Один фарлонг равен 220 ярдам, или 201 168 м.) 

#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter a distance in farlongs: ";
    double farlongs;                                                    // объявление переменной типа double
    cin >> farlongs;                                                    // ввод значения с консоли, с записью в переменную
    cin.get();                                                          // отсечение \n, оставшегося в потоке ввода
    cout << "           Distance in yarsd: " << farlongs / 220 << endl; // вывод в консоль резултата выражения (пробелы для эстетики)
    cin.get();                                                          
}
