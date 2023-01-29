// 1. Перепишите следующий код с использованием синтаксиса списковой инициализации с помощью фигурных скобок;
// в переписанном коде необходимо отказаться от применения массива ar:
class Z200
{
private:
    int j;
    char ch;
    double z;

public:
    Z200(int jv, char chv, zv) : j(jv), ch(chv), z(zv) {}
    //...
};
double x = 8.8;
std::string s = "What a bracing effect!";
int k(99);
Z200 zip(200, 'Z', 0.675);
std::vector<int> ai(5);
int ar[5] = {3, 9, 4, 7, 1};
for (auto pt = ai.begin(), int i = 0; pt != ai.end(); ++pt, ++i)
    *pt = ai[i];

// 2. Какие вызовы функций в следующей короткой программе являются ошибочными и почему?
// На что ссылается аргумент типа ссылки в допустимых вызовах?
#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void rl(const double &rx) { cout << rx << endl; }
void r2(double &rx) { cout << rx << endl; }
void r3(double &&rx) { cout << rx << endl; }
int main()
{
    double w = 10.0;
    rl(w);
    rl(w + l);
    rl(up(w));
    r2(w);
    r2(w + l);
    r2(up(w));
    r3(w);
    r3(w + l);
    r3(up(w));
    return 0;
}

// 3. a. Что отобразит следующая короткая программа и почему?
#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void rl(const double &rx) { cout << "const double & rx\n"; }
void rl(double &rx) { cout << "double & rx\n"; }

// б. Что отобразит следующая короткая программа и почему?
#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void rl(double &rx) { cout << " double & rx\n "; }
void rl(double &&rx) { cout << "double && rx\n"; }
int main()
{
    double w = 10.0;
    rl(w);
    rl(w + 1);
    rl(up(w));
    return 0;
}
// в. Что отобразит следующая короткая программа и почему?
#include <iostream>
using namespace std;
double up(double x) { return 2.0 * x; }
void rl(const double &rx) { cout << " const double & rx \n"; }
void rl(double &&rx) { cout << " double && rx\n"; }
int main()
{
    double w = 10.0;
    rl(w);
    rl(w + 1);
    rl(up(w));
    return 0;
}

// 4. Назовите специальные функции-члены и укажите, что делает их специальными?

// 5. Предположим, что класс Fizzle имеет только данные-члены, как показано ниже:
class Fizzle
{
private:
    double bubbles[4000];
    // ...
};
// Почему этот класс не является подходящим кандидатом для пользовательского конструктора переноса?
// Какое изменение в подходе к хранению 4000 значений double может сделать
// этот класс подходящим кандидатом для функции переноса?

// 6. Перепишите следующую короткую программу, чтобы в ней использовалось лямбда-выражение вместо f1().
// Не изменяйте show2().
#include <iostream>
template <typename T>
void show2(double x, T &fp)
{
    std::cout << x << " -> " << fp(x) << '\n';
}
double fl(double x) { return 1.8 * x + 32; }
int main()
{
    show2(18.0, fl);
    return 0;
}
// 7. Перепишите следующую короткую и неуклюжую программу, чтобы в ней использовалось
// лямбда-выражение вместо функтора Adder. Не изменяйте sum().
#include <iostream>
#include <array>

const int Size = 5;
template <typename T>
void sum(std::array<double, Size> a, T &fp);
class Adder
{
    double tot;

public:
    Adder(double q = 0) : tot(q) {}
    void operator()(double w) { tot += w; }
    double tot_v() const { return tot; };
};
int main()
{
    double total = 0.0;
    Adder ad(total);
    std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    sum(temp_c, ad);
    total = ad.tot_v();
    std::cout << "total: " << ad.tot_v() << '\n';
    return 0;
}
template <typename T>
void sum(std::array<double, Size> a, T &fp)
{
    for (auto pt = a.begin(); pt ! = a.end(); ++pt)
    {
        fp(*pt);
    }
}