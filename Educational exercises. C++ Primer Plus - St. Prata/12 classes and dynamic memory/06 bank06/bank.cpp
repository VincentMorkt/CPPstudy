// 6. Банк "Bank of Heather" интересуется, что произойдет, если установить второй банкомат.
// Модифицируйте код моделирования в данной главе так, чтобы поддерживались две очереди.
// Сделайте так, чтобы клиент присоединялся к первой очереди, если в ней меньше людей, и ко второй - в противном случае.
// Найдите количество клиентов за час, которое приводит к среднему времени ожидания, равному одной минуте.
// (Обратите внимание, что это - нелинейная задача, т.е. удвоение количества банкоматов не удваивает количество клиентов,
// которые могут быть обслужены за час с максимальным ожиданием в одну минуту.)

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
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter the number of simulation hours: "; // ввод количества часов для эмуляции
    int hours;
    cin >> hours;
    if (hours < 100)
    {
        cout << "Error, min number of simulation hours is 100. Value updated to 100\n";
    }
    cout << "Enter the step of changing the number of customers per hour for simulation accuracy (0.1-1 recomendet): "; // ввод количества часов для эмуляции
    double accuracy;
    cin >> accuracy;
    cin.get();

    long cyclelimit = MIN_PER_HR * hours; // количество минут, исходя из времени моделирования

    double perhour = 50; // стартовое значение количества клиентов в час. Программа будет уменьшать его пока среднее время ожидания в моделировании не уменьшится до 1 минуты или меньше

    Item temp;          // данные нового клиента
    long turnaways = 0; // подсчёт недопущенных в основную очередь клиентов
    long customers = 0; // присоеденины к очереди
    long served = 0;    // обслужены во время эмуляции
    long sum_line = 0;  // общая длина очереди
    int wait_time1 = 0; // время до освобождения банкомата
    int wait_time2 = 0; // время до освобождения банкомата
    long line_wait = 0; // общее время очереди

    do // цикл продолжается, пока среднее время ожидания больше 1 минуты
    {
        Queue line1;                                // создание очереди размером по умолчанию. Внутри цикла для обнуления очереди каждый новый цикл
        Queue line2;                                // вторая очередь
        double min_per_cust = MIN_PER_HR / perhour; // среднее время между появлениями
        turnaways = 0;                              // обнуление переменных
        customers = 0;
        served = 0;
        sum_line = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line_wait = 0;
        perhour -= accuracy; // шаг изменения среднего количества клиентов в час
        // запуск моделирования
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust)) // есть подошедший клиент
            {
                if (line1.isfull() && line2.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);                              // cycle - время прибытия
                    if (line1.queuecount() <= line2.queuecount()) // добавление новичка в меньшую очередь
                        line1.enqueue(temp);
                    else
                        line2.enqueue(temp);
                }
            }
            if (wait_time1 <= 0 && !line1.isempty())
            {
                line1.dequeue(temp);       // обслуживание следующего клиента
                wait_time1 = temp.prime(); // в течении wait_time минут
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line += line1.queuecount();

            if (wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);       // обслуживание следующего клиента
                wait_time2 = temp.prime(); // в течении wait_time минут
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 > 0)
                wait_time2--;
            sum_line += line2.queuecount();
        }
    } while ((double)line_wait / served >= 1); // цикл продолжается, пока среднее время ожидания >= 1 минуте.

    // вывод результатов
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl // вывод всех данных, как и в оригинальной программе
             << "customers served: " << served << endl
             << "turnaways: " << turnaways << endl
             << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl
             << "average wait time: " << (double)line_wait / served << " minutes\n"
             << "average customes per hours: " << perhour << endl; // вывод количества клиентов в час
    }
    else
        cout << "No customers!\n";
    cout << "Done\n";
    cin.get();

    return 0;
}

// возвращает true, если в эту минуту появляется клиент
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}