// 1. Начните со следующего объявления класса:

// ...

// Породите класс Сlаssiс, добавив массив членов char, которые будут хранить строку с названием основного произведения на компакт-диске.
// Если необходимо, чтобы какие-то функции в базовом классе были виртуальными, измените объявление базового класса.
// Если объявленный метод не нужен, удалите его из определения. Протестируйте результат с помощью следующей программы:

// ...

// методы базового класса Cd

#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    strncpy(performers, s1, 49); // копирует 49 символов из строки s1 в массив сhar. Защита от слишком длинных строк.
    performers[49] = '\0';       // устанавливает последний элемент массива в нулевой символ (что гарантирует, что массив будет читаться как строка)
    strncpy(label, s2, 19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d) // конструктор копирования
{
    for (int i = 0; i < 50; i++) // почленное копирование массивов
        performers[i] = d.performers[i];
    for (int i = 0; i < 20; i++)
        label[i] = d.label[i];
    selections = d.selections; // прямое копирование остальных членов
    playtime = d.playtime;
}

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = playtime = 0;
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
    for (int i = 0; i < 50; i++) // почленное присваивание массивов
        performers[i] = d.performers[i];
    for (int i = 0; i < 20; i++)
        label[i] = d.label[i];
    selections = d.selections; // прямое присваивание остальных членов
    playtime = d.playtime;
    return *this;
}

// методы производного класса Classic

Classic::Classic(const char *comp, const char *s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
    strncpy(composition, comp, 49);
    composition[49] = '\0';
}

Classic::Classic(const char *comp, Cd &cd) : Cd(cd)
{
    strncpy(composition, comp, 49);
    composition[49] = '\0';
}

Classic::Classic(const Classic &clas) : Cd(clas)
{
    for (int i = 0; i < 50; i++)
        composition[i] = clas.composition[i];
}

Classic::Classic() : Cd()
{
    composition[0] = '\0';
}

Classic::~Classic(){};

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Main composition: " << composition << std::endl
              << std::endl;
}

const Classic &Classic::operator=(const Classic &clas)
{
    Cd::operator=(clas);
    for (int i = 0; i < 50; i++)
        composition[i] = clas.composition[i];
    return *this;
}