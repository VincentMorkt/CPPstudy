// 2. Выполните упражнение 1, но для различных строк, используемых двумя классами, вместо массивов фиксированного размера применяйте динамическое выделение памяти.

// 1. Начните со следующего объявления класса:

#include <cstring>
// Базовый класс
class Cd // представляет компакт-диск
{
private:
    char *performers;
    char *label;
    int selections;  // количество сборников
    double playtime; // время воспроизведения в минутах
public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; // выводит все данные о компакт-диске
    const Cd &operator=(const Cd &d);
};

// Породите класс Сlаssiс, добавив массив членов char, которые будут хранить строку с названием основного произведения на компакт-диске.
// Если необходимо, чтобы какие-то функции в базовом классе были виртуальными, измените объявление базового класса.
// Если объявленный метод не нужен, удалите его из определения. Протестируйте результат с помощью следующей программы:

class Classic : public Cd
{
private:
    char *composition;

public:
    Classic(const char *comp, const char *s1, const char *s2, int n, double x); // конструкторы
    Classic(const char *comp, Cd &cd);
    Classic(const Classic &clas); // конструктор копирования
    Classic();                    // конструктор по умолчанию
    ~Classic();
    void Report() const;                           // виртуальная функция
    const Classic &operator=(const Classic &clas); // операция присваивания
};
