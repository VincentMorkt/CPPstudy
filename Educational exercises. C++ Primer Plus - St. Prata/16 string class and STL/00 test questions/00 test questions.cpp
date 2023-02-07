;
/*
// 1. Пусть имеется следующее объявление класса:
#include <cstring>

class RQ1
{
private:
    char *st; // указатель на строку в стиле С
public:
    RQ1()
    {
        st = new char[1];
        strcpy(st, "");
    }
    RQ1(const char *s)
    {
        st = new char[strlen(s) + 1];
        strcpy(st, s);
    }
    RQ1(const RQ1 &rq)
    {
        st = new char[strlen(rq.st) + 1];
        strcpy(st, rq.st);
    }
    ~RQ1() { delete[] st; }
    RQ1 &operator=(const RQ1 &rq);
    // Другие операторы
};
// Преобразуйте его в объявление, использующее объект string. Какие методы
// больше не нуждаются в явных определениях?
#include <string>
class RQ1
{
private:
    std::string st; // указатель на строку в стиле С
public:
    RQ1() : st() // используется конструктор string по умолчанию
    {
        // st = new char[1];
        // strcpy(st, "");
    }
    RQ1(const char *s) : st(s) // используется конструктор string
    {
        // st = new char[strlen(s) + 1];
        // strcpy(st, s);
    }
    // RQ1(const RQ1 &rq) // автоматический конструктор копирования не требует переопределения
    // {
    //     st = new char[strlen(rq.st) + 1];
    //     strcpy(st, rq.st);
    // }
    // ~RQ1() { delete[] st; }        // автоматический деструктор не требует переопределения
    // RQ1 &operator=(const RQ1 &rq); // автоматический оператор присваивания не требует переопределения
    // Другие операторы
};

// 2. Назовите хотя бы два преимущества объектов string по сравнению со строками
// в стиле С с точки зрения простоты применения.
// объекты string имеют перегруженные операции для простого присваивания, сравнения и т.д.
// объекты string самостоятельно управляют памятью, нет проблем с динамической памятью или выходом за пределы массива

// 3. Напишите функцию, которая принимает ссылку на объект string в качестве
// аргумента и затем преобразует объект string в прописные буквы.
#include <algorithm>
#include <cstring>
#include <string>
// #include <cstdlib>
void tolower_str(std::string &st)
{
    std::for_each(st.begin(),st.end(), tolower);
}

// 4. Какие из следующих операторов не являются примерами корректного использования
// (концептуально или синтаксически) объекта auto_ptr?
// (Предполагается, что все необходимые заголовочные файлы включены.)
// auto_ptr<int> pia(new int[20]); // необходимо использовать new [], указатель на массив может создавать только unique_ptr, поскольку имеет версию с delete []
// auto_ptr<string>(new string);   // неименованный указатель, не имеет смысла, поскольку объекты auto_ptr нельзя присваивать
// int rigue = 7;
// auto_ptr<int> pr(&rigue); // нельзя создавать динамический указатель на не-динамический объект (это приведёт к попытке применить delete к стеку памяти, что неверно)
// auto_ptr dbl(new double); // неправильный синтаксис, необходимо указать <тип> для шаблонного класса, указатель на который создаётся

// 5. Если бы можно было создать механический эквивалент стека, который хранит
// клюшки для гольфа вместо номеров, почему он был бы (концептуально) плохой
// сумкой для гольфа? 
// можно было бы доставать клюшки только в очерёдности, обратной их помещению в сумку (последней положил, первой достал). 
// Чтобы добраться до нужной клюшки необходимо достать из сумки все, которые были туда помещены после неё.

// 6. Почему контейнер set - неудачный выбор для хранения записей о полученных
// очках в гольфе в формате "от лунки к лунке"? 
// не знаю ничего о гольфе и его форматах, но контейнер set хранит отсортированные уникальные значения.
// следовательно в соответствующем формате значения не должны быть отсортированными, либо могут повторяться.

// 7. Если указатель - это итератор, почему разработчики STL просто нс используют его вместо итераторов?
// Иттераторы применимы там, где нельзя использовать указатели. Иттератор - обобщённый указатель, который позволяет применять 
// одни и те же операции с различными видами организации данных.

// 8. Почему разработчики STL не определили базовый класс итератора,
// используя наследование для порождения классов для других типов итераторов,
// и не выразили алгоритмы в терминах этих классов итераторов?
// для возможности работы с обычными массивами и указателями на них, 
// которые не могут быть базовым классом для итераторов, поскольку не являются классами

// 9. Приведите, как минимум, три примера, показывающих преимущества объекта
// vector по сравнению с обычным массивом.
// 1. Вектор имеет встроенные методы и перегруженные операции для управления данными
// 2. Вектор имеет динамический размер, который может быть автоматически увеличен или уменьшен при необходимости
// 3. ??????????????????????????????????????????
*/
// 10. Если в коде из листинга 16.9 использовать list вместо vector, то какие части
// программы станут некорректными? Легко ли они могут быть исправлены? Если да, то как?

// некоректными станут функции сортировки, вместо них необходимо будет использоваеть метод сортировки
// функция random_shuffle также станет недоступна, и аналога для неё среди метдодов списка нет.
// всё из за использования функциями итераторов свободного доступа, которые не предоставляет list

// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

struct Review {
    std::string title;
    int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
int main()
{
    using namespace std;

    list<Review> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(temp);
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
              << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview); 

        books.sort(); // необходимо использовать books.sort();
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        random_shuffle(books.begin(), books.end()); 
        // невозможно применить к list, поскольку список не имеет иттератора произвольного доступа, и собственного альтернативного метода.
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    cin.get();
    return 0;
}

bool operator<(const Review & r1, const Review & r2)
{
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
    if (r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl; 
}
