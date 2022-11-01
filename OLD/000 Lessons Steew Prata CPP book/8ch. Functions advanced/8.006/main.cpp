// 6. Напишите шаблонную функцию maxn(), которая принимает в качестве аргумента массив элементов типа T и целое число, представляющее количество элементов в массиве,
// а возвращает элемент с наибольшим значением. Протестируйте ее работу в программе, которая использует этот шаблон с массивом из шести значений int и массивом из четырех значений double.
// Программа также должна включать специализацию, которая использует массив указателей на char в качестве первого аргумента и количество указателей - в качестве второго,
// а затем возвращает адрес самой длинной строки. Если имеется более одной строки наибольшей длины, функция должна вернуть адрес первой из них.
// Протестируйте специализацию на массиве из пяти указателей на строки.

#include <iostream>
#include <cstring>

template <typename T>
T maxn(T arrName[], int size);
template <>
const char *maxn<const char *>(const char *arrName[], int size);

int main()
{
    using namespace std;
    int intArr[6] = {1, 6, 2, 5, 3, 4};
    double doubleArr[4] = {1.1, 4.4, 2.2, 3.3};

    const char *charArr[16] =
        {
            "Yobani bomzhi, shcho ne bachyly asfaltu",
            "Skachut na butylkakh vpered",
            "Mama, ya nie znal, ya ni razu nie strielial",
            "Mama, mnie nassali v bieriet",
            "Padlo neosvichene na tanku prypyzdaiachylo",
            "Padlu rozneslo po kushcham",
            "Druha padla bihla v posadku khovatysia",
            "Ale tezh distalas shchuram",
            "Khto vas, suka, klykav siudy, nakhui vy tut vsralysia?",
            "Khui vam, bliadiam, a ne rai",
            "Palymo tanky z nochi do ranku",
            "Trupamy vsteleno krai",
            "De vy nakhui vzialysia, z yakoi nory?",
            "I khto vas, suka, vysrav na tsei svit?",
            "Ta ruka ne vtomytsia dosylat patron",
            "Russkyi pidaras - HORY!"};

    cout << maxn(intArr, 6) << endl
         << maxn(doubleArr, 4) << endl
         << maxn(charArr, 16) << endl;
    cin.get();
    return 0;
}

template <>
const char *maxn<const char *>(const char *arrName[], int size)
{
    const char *temp = arrName[0];
    for (int i = 1; i < size; i++)
        if (strlen(temp) > strlen(arrName[i]))
            continue;
        else
            temp = arrName[i];
    return temp;
}

template <typename T>
T maxn(T arrName[], int size)
{
    T temp = arrName[0];
    for (int i = 1; i < size; i++)
        temp = (temp > arrName[i]) ? temp : arrName[i];
    return temp;
}