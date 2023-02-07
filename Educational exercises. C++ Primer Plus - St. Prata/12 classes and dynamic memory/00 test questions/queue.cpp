// queue.cpp -- методы классов Queue и Customer

#include <cstdlib>
#include "queue.h"

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node *temp;
    while (front != nullptr) // пока очередь не пуста
    {
        temp = front;        // сохранение адреса начального элемента
        front = front->next; // переустановка указателя на следующий элемент
        delete temp;         // удаление предыдущего начального элемента
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// добавление елемента в очередь
bool Queue::enqueue(const Item &item)
{
    if (isfull())
        return false;
    Node *add = new Node; // создание узла
    add->item = item;     // занесение указателей на узлі
    add->next = nullptr;
    items++;
    if (front == nullptr) // если очередь пуста
        front = add;      // элемент помещается в начало
    else
        rear->next = add; // иначе он помещается в конец
    rear = add;           // указатель конца указывает на новый узел
    return true;
}

// помещение элемента front в переменную item и его удаление зи очереди
bool Queue::dequeue(Item &item)
{
    if (front == nullptr)
        return false;
    item = front->item; // в item заносится первый элемент из очереди
    items--;
    Node *temp = front;  // сохранение местоположения первого элемента
    front = front->next; // сдвиг указателя начала на следующий элемент
    delete temp;         // удаление предыдущего первого элемента
    if (items == 0)
        rear = nullptr;
    return true;
}

// метод класса Customer
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1; // время обслуживания выбирается случайным образом
    arrive = when;                     // фиксация времени прибытия
}

