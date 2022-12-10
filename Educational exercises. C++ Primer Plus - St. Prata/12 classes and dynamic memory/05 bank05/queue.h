// 5. Исследование банка "Bank of Heather" показало, что клиенты банкомата не ожидают в очереди более одной минуты. 
// С помощью модели из листинга 12.10 найдите количество клиентов за час, которое приводит к среднему времени ожидания, равному одной минуте. 
// (Применяйте по меньшей мере 100-часовый период моделирования.) 

// queue.h -- интерфейс для очереди

#ifndef QUEUE_H_
#define QUEUE_H_

class Customer
{
private:
    long arrive;     // момент появления клиента
    int processtime; // время обслуживания клиента
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int prime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    struct Node
    {
        Item item;
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
    bool enqueue(const Item &item); // добавление элемента в конец очереди
    bool dequeue(Item &item);       // удаление элемента из начала очереди
};
#endif