// potr.cpp -- определение методов классов Port и VintagePort

#include <ostream>
#include <cstring>
#include "port.h"

// а. Первое задание - нужно заново создать определения методов Port, т.к. предыдущий администратор уничтожил свой код.

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[strlen(st) + 1];
    strcpy(brand, br);
    strncpy(style, st, 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port &p) // конструктор копирования
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    for (int i = 0; i < 20; i++)
    {
        style[i] = p.style[i];
        if (style[i] == '\0')
            break;
    }
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if (this == &p)
        return *this;
    delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    for (int i = 0; i < 20; i++)
    {
        style[i] = p.style[i];
        if (style[i] == '\0')
            break;
    }
    bottles = p.bottles;
    return *this;
}

Port &Port::operator+=(int b) // добавляет b к bottles
{
    bottles += b;
    return *this;
}

Port &Port::operator-=(int b) // вычитает b из bottles, если это возможно
{
    if (bottles >= b)
        bottles -= b;
    return *this;
}

void Port::Show() const
{
    using std::endl;
    std::cout << "Brand: " << brand << endl
              << "Kind: " << style << endl
              << "Bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

// б. Второе задание - объясните, почему одни методы переопределены, а другие нет.

// переопределён только метод show. отображение для базового и производного классов будут отличаться, поскольку в производном добавляется два членна данных
// методы operator+=, operator-= и BottleCount() не требуют переопределиня, метод базового класса будет корректо применяться с объектами производного класса

// в. Третье задание - объясните, почему функции operator=() и operator<<() не определены как виртуальные.
// operator=() не определён как виртуальный, поскольку каждый класс должен иметь свою собственную операцию копирования
// дружественная функция friend ostream &operator<< не определена как виртуальная, потому что это невозможно, дружественные функции не наследуются

// г. Четвертое задание - обеспечьте определения для методов VintagePort.

VintagePort::VintagePort() // конструктор базового класса не вызывается явно, поэтому будет использован конструктор по умолчанию
{
    nickname = new char[5];
    strcpy(nickname, "none");
    year = 0;
}
VintagePort::VintagePort(const char *br, const char *st, int b, const char *nn, int y) : Port(br, st, b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const Port &p, const char *nn, int y) : Port(p)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl
              << "Year: " << year << std::endl;
}
ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}