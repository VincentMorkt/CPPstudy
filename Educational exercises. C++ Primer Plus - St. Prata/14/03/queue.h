// 3. Определите шаблон QueueTp. Протестируйте его, создав очередь, указателей на Worker (см. листинг 14.10),
// и примените его в программе, такой как приведенная в листинге 14.12.

// queue.h -- интерфейс для очереди
#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T item;
        struct Node *next;
    };
    enum
    {
        Q_SIZE = 10
    };
    Node *front;     // указатель на начало Queue
    Node *rear;      // указатель не конец Queue
    int items;       // текущее количество элементов в Queue
    const int qsize; // максимальное количество элементов в Queue

    // упреждающие объявления для предотвращения открытого копирования
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int qs = Q_SIZE); // создание очереди с предельным размером qs
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T &item); // добавление элемента в конец очереди
    bool dequeue(T &item);       // удаление элемента из начала очереди
};


template <typename T> Queue<T>::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename T> Queue<T>::~Queue()
{
    Node *temp;
    while (front != nullptr) // пока очередь не пуста
    {
        temp = front;        // сохранение адреса начального элемента
        front = front->next; // переустановка указателя на следующий элемент
        delete temp;         // удаление предыдущего начального элемента
    }
}

template <typename T> bool Queue<T>::isempty() const
{
    return items == 0;
}

template <typename T> bool Queue<T>::isfull() const
{
    return items == qsize;
}

template <typename T> int Queue<T>::queuecount() const
{
    return items;
}

// добавление елемента в очередь
template <typename T> bool Queue<T>::enqueue(const T &item)
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
template <typename T> bool Queue<T>::dequeue(T &item)
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

#endif