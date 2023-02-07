// bank.cpp -- использование интрефейса Queue

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // появился ли новый клиент?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;


    // подготовка
    std::srand(std::time(0)); // случайная инициализация rand
    cout << "Case Study: Bank of Heather Automatic Teller\n"
         << "Enter maximum size of queue: "; // ввод максимального размера очереди
    int qs;
    cin >> qs;
    Queue line(qs);                                   // создание очереди из qs элементов
    cout << "Enter the number of simulation hours: "; // ввод количества часов для эмуляции
    int hours;
    cin >> hours;

    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: "; // ввод количества клиентов в час
    double perhour;
    cin >> perhour;
    double min_per_cust = MIN_PER_HR / perhour; // среднее время между появлениями

    Item temp;          // данные нового клиента
    long turnaways = 0; // подсчёт недопущенных в основную очередь клиентов
    long customers = 0; // присоеденины к очереди
    long served = 0;    // обслужены во время эмуляции
    long sum_line = 0;  // общая длина очереди
    int wait_time = 0;  // время до освобождения банкомата
    long line_wait = 0; // общее время очереди

    // запуск моделирования
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust)) // есть подошедший клиент
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle - время прибытия
                line.enqueue(temp); // добавление новичка в очередь
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);       // обслуживание следующего клиента
            wait_time = temp.prime(); // в течении wait_time минут
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
    }

    // вывод результатов
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl
             << "customers served: " << served << endl
             << "turnaways: " << turnaways << endl
             << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl
             << "average wait time: " << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done\n";
    cin.get();
    cin.get();
    return 0;
}

// возвращает true, если в эту минуту появляется клиент
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}