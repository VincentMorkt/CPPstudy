// 2. Ниже показано объявление класса Cpmv:
#ifndef _CPMV_H_

#define _CPMV_H_

#include <string>
#include <iostream>
#include <iomanip>
class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };

private:
    Info *pi;

public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv &ep);
    Cpmv(Cpmv &&mv);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &ep);
    Cpmv &operator=(Cpmv &&mv);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};
// отображение адреса указателя на структуру Info и данных структуры string qcode и string zcode;
void Cpmv::Display() const
{
    std::cout << "pi adress: " << pi << std::endl;
    if (pi != nullptr)
        std::cout << "    qcode: " << pi->qcode << std::endl
                  << "    zcode: " << pi->zcode << std::endl
                  << std::endl;
}
// конструктор по умолчанию
Cpmv::Cpmv()
{
    pi = new Info;
    pi->qcode = {""};
    pi->zcode = {""};
    std::cout << "--constructor deafult--" << std::endl;
    Display();
}
// конструктор (string, string)
Cpmv::Cpmv(std::string q, std::string z)
{
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
    std::cout << "--constructor base--" << std::endl;
    Display();
}
// конструктор копирования
Cpmv::Cpmv(const Cpmv &ep)
{
    pi = new Info;
    pi->qcode = ep.pi->qcode;
    pi->zcode = ep.pi->zcode;
    std::cout << "--constructor copy--" << std::endl;
    std::cout << "from" << std::endl;
    ep.Display();
    std::cout << "to" << std::endl;
    Display();
}
// конструктор переноса
Cpmv::Cpmv(Cpmv &&mv)
{
    std::cout << "--constructor move--" << std::endl;
    std::cout << "from" << std::endl;
    mv.Display();
    pi = mv.pi;          // указатель текущего объекта указывает на данные объекта, переданного в аргументе
    mv.pi = nullptr;     // указателю объекта, переданному в аргументе присваивается адрес нулевого указателя
    std::cout << "to" << std::endl;
    Display();
}
// деструктор
Cpmv::~Cpmv()
{
    std::cout << "--destructor--" << std::endl;
    Display();
    delete pi;
}
// перегруженный оператор присваивания через копирование
Cpmv &Cpmv::operator=(const Cpmv &ep)
{
    std::cout << "--operator= (copy)--" << std::endl;
    std::cout << "from" << std::endl;
    ep.Display();
    if (this == &ep)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = ep.pi->qcode;
    pi->zcode = ep.pi->zcode;
    std::cout << "to" << std::endl;
    Display();
    return *this;
}
// перегруженный оператор присваивания через перенос
Cpmv &Cpmv::operator=(Cpmv &&mv)
{
    std::cout << "--operator= (move)--" << std::endl;
    std::cout << "from" << std::endl;
    mv.Display();

    if (this == &mv) // если этот объект присваивается сам себе, то просто вовзращаем указатель на него
        return *this;

    delete pi;       // удаляем старый указатель
    pi = mv.pi;      // указатель текущего объекта теперь указывает на данные объекта из аргумента
    mv.pi = nullptr; // указателю объекта, переданному в аргументе присваивается адрес нулевого указателя

    std::cout << "to" << std::endl;
    Display();
    return *this;
}
// оператор конкатенации членов-данных вложенной структуры
Cpmv Cpmv::operator+(const Cpmv &obj) const
{
    std::cout << "--operator+ --" << std::endl;
    Cpmv temp(pi->qcode + obj.pi->qcode, pi->zcode = pi->zcode + obj.pi->zcode);
    // создание временного объекта для конкатенации членов данных. Оператор + не должен изменять исходные данные
    return temp; // возврат временногоо объекта (будет создана временная копия временного объекта)
}

#endif

// Функция operator+() должна создавать объект, члены qcode и zcode которого
// являются результатом конкатенации соответствующих членов операндов.
// Напишите код, который реализует семантику переноса для конструктора переноса
// и операции присваивания с переносом. Напишите программу, использующую все методы класса Cpmv.
// В целях тестирования обеспечьте выдачу сообщений в методах,
// чтобы можно было увидеть, когда они используются.