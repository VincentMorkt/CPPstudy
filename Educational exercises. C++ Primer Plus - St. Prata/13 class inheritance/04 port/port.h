// 4. Союз программистов-меценатов собирает коллекцию бутылочного портвейна. Для ее описания администратор союза разработал класс Port:

// port.h -- объявление класса

#include <iostream>
#include <cstring>

using namespace std;
class Port // портвейн
{
private:
    char *brand;
    char style[20]; // например, tawny (золотистый), ruby (рубиновый), vintage (марочный)
    int bottles;

public:
    Port(const char *br = "none", const char *st = "none", int b = 0);
    Port(const Port &p); // конструктор копирования
    virtual ~Port() { delete[] brand; }
    Port &operator=(const Port &p);
    Port &operator+=(int b); // добавляет Ь к bottles
    Port &operator-=(int b); // вычитает Ь из bottles, если это возможно
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream &operator<<(ostream &os, const Port &p);
};

// Метод Show() вводит информацию в следующем формате:
// Brand: Gallo
// Kind: tawny
// Bottles: 20

// Функция operator<<() представляет информацию в следующем формате(без символа новой строки в конце):
// Gallo, tawny, 20

// Завершив определения методов для класса Port, администратор написал производный класс Vintage Port, прежде чем был уволен:

class VintagePort : public Port // style обязательно = "vintage"
{
private:
    char *nickname; // т.е. "The Noble" , "Old Velvet" и т.д.
    int year;       // год сбора

public:
    VintagePort();
    VintagePort(const char *br, const char *st, int b, const char *nn, int y); // const char *st добавлено, за что-то же был уволен предыдущий програмист, а тут явно не хватает аргумента
    VintagePort(const Port & p, const char *nn = "none", int y = 0);
    VintagePort(const VintagePort &vp);
    ~VintagePort() { delete[] nickname; }
    VintagePort &operator=(const VintagePort &vp);
    void Show() const;
    friend ostream &operator<<(ostream &os, const VintagePort &vp);
};

// Вам поручено завершить разработку класса VintagePort.


