// 6. Повторите пример, показанный в листинге 12.12, 
// используя шаблон queue класса STL вместо класса Queue, который был описан в главе 12.

// customer.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_

#include <cstdlib>         // (or stdlib.h) for rand()

// This queue will contain Customer items


class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() : arrive(0), processtime (0){}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when; 
}

typedef Customer Item;

#endif
