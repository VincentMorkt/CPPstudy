// 5. Пусть имеется следующее объявление структуры:
// struct customer
// {
//     char fullname[35];
//     double payment;
// };
// Напишите программу, которая будет добавлять структуры заказчиков в стек и удалять их из стека, представленного объявлением класса Stack.
// Всякий раз, когда заказчик удаляется из стека, его зарплата должна добавляться к промежуточной сумме и по этой сумме выдаваться отчет.
// На заметку: вы должны иметь возможность пользоваться классом Stack без изменений;
// просто поменяйте объявление typedef, чтобы Item был типом customer вместо unsigned long.

// main.cpp -- программа демонстратор

#include <iostream>
#include <cctype>
#include "stack.h"
int main()
{
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    customer po;
    double sumPayment = 0;
    cout << "Please enter A to add a customer,\n"       // введите А для добавления елемента в стек,
         << "P to process a customer, or Q to quit.\n"; // Р для удаления, или Q для выхода

    while (cin >> ch && toupper(ch) != 'Q') // ввод ch и проверка, не введено ли Q или q
    {
        while (cin.get() != '\n') // отсечение всего что следует после введённого символа до \n
            continue;
        if (!isalpha(ch)) // проверка, введена ли буква
        {
            cout << '\a'; // сигнал об ошибке (звуковой)
            continue;     // новый цикл
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            if (st.isfull()) // если стак полон, ввод не будет осуществляться
            {
                cout << "stack already full\n";
                break;
            }
            cout << "Enter a customer name to add: "; // ввод имени
            cin.get(po.fullname, 35);                 // функция cin.get()
            while (cin.get() != '\n')                 // отсечение всего что следует после введённого символа до \n
                continue;
            cout << "Enter a customer payment to add: ";

            while (!(cin >> po.payment)) // если ввод не был успешн, выполняется тело цика, иначе переход к следующему оператору
            {
                cout << "\a ERROR, enter number!\n";
                cin.clear();              // очистка флага failbit
                while (cin.get() != '\n') // отсечение всего что следует после введённого символа до \n
                    continue;
            }
            st.push(po); // запись введённой структуры в стек
            break;
        case 'P':
        case 'p':
            if (st.isempty()) // проверка, пуст ли стек
                cout << "stack already empty\n";
            else
            {
                st.pop(po);                                               // выталкивание последнего элемента из стека
                sumPayment += po.payment;                                 // прибавление зарплаты к промежуточной сумме
                cout << "Sum of payment = " << sumPayment << " popped\n"; // отображение суммы
            }
            break;
        }
        cout << "\nPlease enter A to add a purchase order,\n" // приглашение к вводу
             << "P to process a PO, or Q to quit.\n";
    }
    return 0;
}
