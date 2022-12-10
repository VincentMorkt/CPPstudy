// 4. Имеется следующий вариант класса Stack, определенного в листинге 10.10:
// Как понятно из закрытых членов, данный класс использует динамически выделенный массив для хранения элементов стека.
// Перепишите методы для соответствия новому представлению и напишите программу, которая демонстрирует работу
// всех методов, включая конструктор копирования и операцию присваивания.

// stack.cpp -- Stack member functions

#include "stack.h"
Stack::Stack(int n) // create an empty stack
{
    pitems = new Item[n];
    size = n;
    top = 0;
}

Stack::Stack(const Stack &st)
{
    pitems = new Item[st.size];          // создание нового динамического массива, размером равным инициализирующему
    if (top > 0)                         // если хотя-бы одна ячейка заполнена
        for (int i = 0; i < st.top; i++) // цикл соответствует количеству заполненных ячеек стека
            pitems[i] = st.pitems[i];    // почленное копирование всех заполненных ячеек
    size = st.size;                      // копирование размера
    top = st.top;                        // копирование индекса верхнего элемента
}

Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item &item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack &Stack::operator=(const Stack &st)
{
    if (this == &st)
        return *this;
    delete[] pitems;
    pitems = new Item[st.size];          // создание нового динамического массива, размером равным инициализирующему
    if (top > 0)                         // если хотя-бы одна ячейка заполнена
        for (int i = 0; i < st.top; i++) // цикл соответствует количеству заполненных ячеек стека
            pitems[i] = st.pitems[i];    // почленное копирование всех заполненных ячеек
    size = st.size;                      // копирование размера
    top = st.top;                        // копирование индекса верхнего элемента
    return *this;
}
