#include <iostream>
#include <cstring>
#include "queue.h"
#include "workermi.h"

const int SIZE = 5;

int main()
{
    using namespace std;
    Queue<Worker *> lolas(SIZE);
    int ct;
    Worker *lol;
    while (!lolas.isfull()) // пока очередь не заполнена
    {
        char choice;
        cout << "Enter the persone category: \n"
             << "a: Waiter          b: Singer\n"
             << "c: Singing Waiter  q: quit\n";
        cin >> choice;
        while (strchr("abcq", choice) == nullptr)
        {
            cout << "Please enter a a, b, c, or q: ";
            cin >> choice;
        }
        cin.get();
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'a':
            lol = new Waiter;
            lolas.enqueue(lol);
            break;
        case 'b':
            lol = new Singer;
            lolas.enqueue(lol);
            break;
        case 'c':
            lol = new SingingWaiter;
            lolas.enqueue(lol);
            break;
        }
        lol->Set();
        cout << endl;
    }
    cout << "\nHere is your team:\n\n";
    int i;
    while (!lolas.isempty())
    {
        lolas.dequeue(lol);
        lol->Show();
        cout << endl;
        delete lol; // delete теперь здесь
    }
    // for (i = 0; i < ct; i++)
    //     delete lolas[i];
    cout << "Bye.\n";
    cin.get();
    return 0;
}