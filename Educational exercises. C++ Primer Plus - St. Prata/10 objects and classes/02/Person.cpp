// 2. Пусть имеется определение следующего простого класса:

// (В нем используется объект string и символьный массив, так что вы сможете сравнить применение этих двух форм.)
// Напишите программу, которая дополнит реализацию за счет предоставления кода для пока еще не определенных методов.
// В программе, использующей класс, должны также присутствовать вызовы трех возможных конструкторов
// (без аргументов, с одним аргументом, с двумя аргументами) и двух методов отображения.
// Ниже приведен пример применения этих конструкторов и методов:
// и т.д. для объектов two и three

// person.cpp -- определение классов, методов и программа демонстратор

#include <iostream>
#include <cstring>
using namespace std;

// --- определение класса --- //
class Person
{
private:
    static const int LIMIT = 25;
    string lname;      // имя
    char fname[LIMIT]; // фамилия

public:
    Person()
    {
        lname = " ";
        fname[0] = '\0';
    }                                                    //#1
    Person(const string &ln, const char *fn = "Heyyou"); //#2
    // следующие методы отображают lname и fname
    void Show() const;       // формат: имя фамилия
    void FormalShow() const; // формат: фаимлия, имя
};


// --- реализация методов --- //
Person::Person(const string &ln, const char *fn)
{
    lname = ln;                // простое присвоение доступное объектам  класса string
    strncpy(fname, fn, LIMIT); // функция strncpy для копирования символов из строкового литералла в строку
    fname[LIMIT] = '\0';       // присваивание последнему символу символьного массива значения нулевого символа, поскольк strncpy этго не гарантирует
}

void Person::Show() const
{
    cout << lname << " " << fname << endl; // cout обрабатывает символьные массивы как строковые литералы, поэтому тут не требуется ничего дополнительного
}
void Person::FormalShow() const
{
    cout << fname << ", " << lname << endl;
}

// --- программа демонестратор --- //
int main()
{
    Person one;                      // используется конструетор по умолчанию
    Person two("Smythecraft");       // используется конструктор #2 с одним аргументом по умолчанию
    Person three("Dimwiddy", "Sam"); // используется конструктор #2 без аргументов по умолчанию

    one.Show(); // демонстрация работы методов
    cout << endl;
    one.FormalShow();
    cout << endl;

    two.Show();
    cout << endl;
    two.FormalShow();
    cout << endl;

    three.Show();
    cout << endl;
    three.FormalShow();
    cout << endl;

    cin.get();
    return 0;

}