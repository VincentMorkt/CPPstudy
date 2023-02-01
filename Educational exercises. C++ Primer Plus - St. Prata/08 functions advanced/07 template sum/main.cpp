// 7. Измените программу из листинга 8.14 так, чтобы использовать две шаблонных функции по имени SumArray(),
// возвращающие сумму содержимого массива вместо его отображения.
// Программа должна сообщать общее количество предметов и сумму всех задолженностей (debts).

// tempover.cpp --- template overloading
#include <iostream>

template <typename T> // template A
T SumArray(T arr[], int n);

template <typename T> // template B
T SumArray(T *arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    const int NumOfThings = 6;
    const int NumOfDebts = 3;
    int things[NumOfThings] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[NumOfDebts] =
        {
            {"Ima Wolfe", 2400.0},
            {"Ura Foxe", 1300.0},
            {"Iby Stout", 1800.0}};
    double *pd[NumOfDebts];

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < NumOfDebts; i++)
        pd[i] = &mr_E[i].amount;

    cout << "Num of things:" << NumOfDebts << endl
         << "Sum of things :" << SumArray(things, NumOfThings) << endl
         << "Num of Mr. E's debts: " << NumOfDebts << endl
         << "Sum of Mr. E's debts: " << SumArray(pd, NumOfDebts) << endl; 
    cin.get();
    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

template <typename T>
T SumArray(T *arr[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
        sum += *arr[i];
    return sum;
}
