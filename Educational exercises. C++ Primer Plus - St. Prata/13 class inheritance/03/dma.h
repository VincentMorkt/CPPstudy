// 3. Перепишите иерархию классов baseDMA-lacksDMA-hasDMA таким образом, чтобы все три класса были порождены от абстрактного базового класса.
// Протестируйте результат с помощью программы, подобной приведенной в листинге 13.10. То есть она должна использовать массив указателей
// на абстрактный базовый класс и позволять пользователю принимать во время работы программы решения о том, объекты какого типа создавать.
// Добавьте в определения классов виртуальные методы View() для управления выводом данных.

// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// absDMA -- абстрактный базовый класс
class absDMA
{
private:
    char *label;
    int rating;

public:
    absDMA(const char *l = "null", int r = 0); // конструктор с аргументами по умолчанию
    absDMA(const absDMA &rs);                  // конструктор копирования
    virtual ~absDMA() = 0;                     // нулевой виртуальный деструктор
    absDMA &operator=(const absDMA &rs);       // оператор присваивания
    virtual void View();                       // виртуальная функция вывода данных
};

//  baseDMA -- простой производный класс
class baseDMA : public absDMA
{
public:
    baseDMA(const char *l = "null", int r = 0) : absDMA(l, r) {} // конструктор с аргументами по умолчанию
    // поскольку производный класс не имеет никаких членов-данных,
    // нам подойдут автоматические конструктор копирования, деструктор и оператор присваивания
    void View();                                                    // фунеция вывода данных
    friend std::istream &operator>>(std::istream &is, baseDMA &rs); // метод ввода - дружественная функция с перегруженным оператором. Почему бы нет?
};

// lacksDMA -- производный класс во втором поколении
class lacksDMA : public baseDMA
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN]; // член данных - массив char

public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0); // конструктор с аргументами по умолчанию
    lacksDMA(const char *c, const baseDMA &rs);                           // конструктор для инициализации объектами базового класса
    void View();
    friend std::istream &operator>>(std::istream &is, lacksDMA &rs);
};

// derived class with DMA
class hasDMA : public baseDMA
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs);
    void View();
    friend std::istream &operator>>(std::istream &is, hasDMA &rs);
};

#endif