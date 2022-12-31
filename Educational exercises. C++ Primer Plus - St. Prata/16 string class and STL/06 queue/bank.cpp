// 6. Повторите пример, показанный в листинге 12.12, 
// используя шаблон queue класса STL вместо класса Queue, который был описан в главе 12.

// bank.cpp -- using the Queue interface
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <queue>
#include "customer.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::queue;
    // setting things up
    std::srand(std::time(0)); //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Customer> line; // line queue holds up to qs people // modify here

    cout << "Enter the number of simulation hours: ";
    int hours; //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour; //  average # of arrival per hour
    cin >> perhour;
    double min_per_cust; //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;          //  new customer data
    long turnaways = 0; //  turned away by full queue
    long customers = 0; //  joined the queue
    long served = 0;    //  served during the simulation
    long sum_line = 0;  //  cumulative line length
    int wait_time = 0;  //  time until autoteller is free
    long line_wait = 0; //  cumulative time in line

    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust)) // have newcomer
        {
            if (line.size() >= qs) // modify here
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle); // cycle = time of arrival
                line.push(temp); // add newcomer to line // modify here
            }
        }
        if (wait_time <= 0 && !line.empty()) // modify here
        {
            temp = line.front();      // modify here
            line.pop();               // attend next customer // modify here
            wait_time = temp.ptime(); // for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    cin.get();
    cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
