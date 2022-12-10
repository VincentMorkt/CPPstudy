// 2. Усовершенствуйте объявление класса String(т.е. замените stringl.h на string2.h), выполнив перечисленные ниже действия.

// а. Перегрузите операцию + для объединения двух строк в одну.
// б. Напишите функцию-член stringlow(), которая преобразует все буквенныеc имволы в строке в нижний регистр. (Не забудьте о семействе cctype символьных функций.)
// в. Напишите функцию-член stringup(), которая преобразует все буквенные символы в строке в верхний регистр.
// г. Напишите функцию-член, которая принимает аргумент типа char и возвращает количество раз, которое символ появляется в строке.

// string1.h -- fixed and augmented string class definition

#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::istream;
using std::ostream;

class String
{
private:
    char *str;                    // pointer to string
    int len;                      // length of string
    static int num_strings;       // number of objects
    static const int CINLIM = 80; // cin input limit
public:
    // constructors and other methods
    String(const char *s);  // constructor
    String();               // default constructor
    String(const String &); // copy constructor
    ~String();              // destructor
    int length() const { return len; }
    // overloaded operator methods
    String &operator=(const String &);
    String &operator=(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;
    // overloaded operator friends
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);
    // static function
    static int HowMany();

    // функции из задания //
    friend const String operator+(const String &st1, const String &st2); // перегруженный оператор +, возвращает объект, представляющий собой объединённую строку двух операндов.
    // дружественная функция для возможности работы с char* на месте первого аргумента
    void stringlow();       // преобразует все символы в нижний регистр
    void stringup();        // преобразует все символы в верхний регистр
    const int has(char ch); // подсчитывает количество повторений символа в строке
};
#endif
