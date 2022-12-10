// 2. Выполните упражнение 1, но для различных строк, используемых двумя классами, вместо массивов фиксированного размера применяйте динамическое выделение памяти.

// 1. Начните со следующего объявления класса:

// ...

// Породите класс Сlаssiс, добавив массив членов char, которые будут хранить строку с названием основного произведения на компакт-диске.
// Если необходимо, чтобы какие-то функции в базовом классе были виртуальными, измените объявление базового класса.
// Если объявленный метод не нужен, удалите его из определения. Протестируйте результат с помощью следующей программы:

// ...

// методы базового класса Cd

#include <iostream>
#include <cstring>
#include "cd02.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d) // конструктор копирования
{
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections; // прямое копирование остальных членов
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = nullptr;
    label = nullptr;
    selections = playtime = 0;
}

Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}

void Cd::Report() const // выводит все данные о компакт-диске
{
    using std::endl;
    std::cout << endl
              << "Perfomers: " << performers << endl
              << "Label: " << label << endl
              << "selection: " << selections << endl
              << "playtime: " << playtime << endl
              << endl;
}

const Cd &Cd::operator=(const Cd &d)
{
    if (this == &d)
        return *this;
    delete[] performers;
    delete[] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections; // прямое присваивание остальных членов
    playtime = d.playtime;
    return *this;
}

// методы производного класса Classic

Classic::Classic(const char *comp, const char *s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    composition = new char(strlen(comp) + 1);
    strcpy(composition, comp);
}

Classic::Classic(const char *comp, Cd &cd) : Cd(cd)
{
    composition = new char(strlen(comp) + 1);
    strcpy(composition, comp);
}

Classic::Classic(const Classic &clas) : Cd(clas)
{
    composition = new char(strlen(clas.composition) + 1);
    strcpy(composition, clas.composition);
}

Classic::Classic() : Cd()
{
    composition = nullptr;
}

Classic::~Classic()
{
    delete composition;
};

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Main composition: " << composition << std::endl
              << std::endl;
}

const Classic &Classic::operator=(const Classic &clas)
{
    if (this == &clas)
        return *this;
    Cd::operator=(clas);
    delete[] composition;
    composition = new char(strlen(clas.composition) + 1);
    strcpy(composition, clas.composition);
    return *this;
}