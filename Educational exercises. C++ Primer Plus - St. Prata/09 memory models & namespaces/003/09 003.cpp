// 3. Начните со следующего объявления структуры:

struct chaff
{
    char dross[20];
    int slag;
};
// Напишите программу, которая использует операцию new с размещением, чтобы поместить массив из двух таких структур в буфер.
// Затем программа присваивает значения членам структуры (не забудьте воспользоваться функцией strcpy() для массива char)
// и отображает ее содержимое с помощью цикла. Вариант 1 предусматривает применение в качестве буфера памяти статического массива,
// как было показано в листинге 9.10. Вариант 2 состоит в использовании обычной операции new для выделения памяти под буфер.

#include <iostream>
#include <new>
#include <cstring>
const int ISCIImodif = 48;
const int BUF = 512;
const int SIZE = 2;

char buffer[BUF]; // буфер в количестве BUF ячеек размером char (512 байт)

int main()
{
    using namespace std;
    chaff *p1, *p2;                // объявление указателя на структуру
    p1 = new (buffer) chaff[SIZE]; // вариант 1, помещение массива структур в буфер - статический массив, с помощью операции new с размещением
    p2 = new chaff[SIZE];          // вариант 2, помещение массива структур в кучу с помощью обычной операции new

    for (int i = 0; i < SIZE; i++) // цикл для присваивания значений структурам
    {
        strcpy(p1[i].dross, "[ ] var1");  // копирование в член-массив char структуры chaff строки
        p1[i].dross[1] = i + ISCIImodif; // замена 2 символа строки на символ ISCII # i + 48 ('0' & '1')
        p1[i].slag = 1000 + i;           // присвоение члену int структуры chaff значения

        strcpy(p2[i].dross, "[ ] var2"); // вё то же самое для второго варианта
        p2[i].dross[1] = i + ISCIImodif;
        p2[i].slag = 10 + i;
    }
    cout << "----------------Memory adresses:" << endl
         << "static " << (void *)buffer << " | heap: " << p2 << endl
         << endl;

    for (int i = 0; i < SIZE; i++) // цикл для отображения значений
    {
        cout << "p1[" << i << "].dross = " << p1[i].dross << endl
             << "p1[" << i << "].slag = " << p1[i].slag << endl
             << "p1[" << i << "] adress" << &p1[i] << endl
             << endl
             << "p2[" << i << "].dross = " << p2[i].dross << endl
             << "p2[" << i << "].slag = " << p2[i].slag << endl
             << "p2[" << i << "] adress" << &p2[i] << endl
             << endl;
    }
    delete [] p2;

    cout << "---------------------new massives \n\n";
    chaff *p3, *p4;                // объявление указателя на структуру
    p3 = new (buffer) chaff[SIZE]; // вариант 1, помещение массива структур в буфер - статический массив, с помощью операции new с размещением
    p4 = new chaff[SIZE];          // вариант 2, помещение массива структур в кучу с помощью обычной операции new

    for (int i = 0; i < SIZE; i++) // цикл для присваивания значений структурам
    {
        strcpy(p3[i].dross, "[ ] var1-2"); // копирование в член-массив char структуры chaff строки
        p3[i].dross[1] = i + ISCIImodif;  // замена 2 символа строки на символ ISCII # i + 48 ('0' & '1')
        p3[i].slag = 500 + i;            // присвоение члену int структуры chaff значения

        strcpy(p4[i].dross, "[ ] var2-2"); // вё то же самое для второго варианта
        p4[i].dross[1] = i + ISCIImodif;
        p4[i].slag = 50 + i;
    }

    for (int i = 0; i < SIZE; i++) // цикл для отображения значений
    {
        cout << "p3[" << i << "].dross = " << p3[i].dross << endl
             << "p3[" << i << "].slag = " << p3[i].slag << endl
             << "p3[" << i << "] adress" << &p3[i] << endl
             << endl
             << "p4[" << i << "].dross = " << p4[i].dross << endl
             << "p4[" << i << "].slag = " << p4[i].slag << endl
             << "p4[" << i << "] adress" << &p4[i] << endl
             << endl;
    }
    
    delete [] p4;
    cin.get();
    return 0;
}
