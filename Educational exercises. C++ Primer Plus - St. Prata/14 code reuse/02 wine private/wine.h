// 2. Выполните еще раз упражнение 1, но вместо включения используйте закрытое наследование. 
// Здесь также могут пригодиться несколько объявлений typedef. 
// Подумайте, как можно применить следующие операторы: 

// PairArray::operator=(PairArray(ArrayInt(), ArrayInt())); 
// cout << (const string &) (*this); 

// получеппый класс должен работать с тестовой программой, приведенной в упражнении 1.

// 1 . Класс Wine(Вино) содержит объект-член типа string (см. главу 4) для названия
// вина и объект Pair из объектов valarray<int> (рассматривались в этой главе).
// Первый член каждого объекта Pair содержит год сбора винограда, а второй член
// - количества бутылок с вином урожая этх лет.
// Например, первый объект valarray - количества бутылок: 24 , 48 и 144.
// Хорошо бы, чтобы объект Wine содержал целочисленный член для хранения возраста вина в годах.
// Для упрощения кода могут быть полезными следующие объявления typedef:
#ifndef _WINE_H_
#define _WINE_H_

#include <valarray>
#include <iostream>

// Таким образом, тип PairArray представляет тип Pair<std::valarray<int>, std::valarray<int>>.

template <typename F, typename S>
class Pair
{
private:
    F a;
    S b;

public:
    Pair(const F &f, const S &s) : a(f), b(s) {}
    Pair() {}
    F first() const { return a; }
    S second() const { return b; }
    F &first() { return a; }
    S &second() { return b; }
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

// Реализуйте класс Wine, используя включение.

class Wine : private Pair<ArrayInt, ArrayInt>
{
private:
    std::string label;
    // PairArray yearsAndNum;
    int years;

public:
    // Этот класс должен иметь конструктор по умолчанию и, как минимум, следующие конструкторы:

    // Инициализация label значением l, количество лет - у, годы урожая - yr[], количество бутылок - bot[]
    Wine(const char *l, int y, const int yr[], const int bot[]) 
    : Pair(ArrayInt(yr, y),ArrayInt(bot, y)), label(l), years(y) {}
    // Инициализация label значением l, количество лет - у, создаются объекты массива размером у
    explicit Wine(const char *l = "none", int y = 0) // по совместительству конструктор по умолчанию
    : Pair(ArrayInt(y),ArrayInt(y)), label(l), years(y) {}
    void GetBottles();
    std::string &Label() { return label; }
    int sum();
    void Show();
};

void Wine::GetBottles()
{
    using namespace std;
    ArrayInt _years(years);
    ArrayInt _num(years);
    cout << "Enter " << label << " data for " << years << " year(s)" << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "Enter year: ";
        cin >> first()[i];
        cout << "Enter bottles for that year: ";
        cin >> second()[i];
    }
    cin.get();
}

int Wine::sum()
{
    int sum;
    for (int i = 0; i < years; i++)
       sum += second()[i];
    return sum;
}

void Wine::Show()
{
    using namespace std;
    cout << "Wine: " << label << endl
         << "\tYear\tBottles\n";
    // ArrayInt tempF = yearsAndNum.first();
    // ArrayInt tempS = yearsAndNum.second();
    for (int i = 0; i < years; i++)
        cout << '\t' << first()[i] << '\t' << second()[i] << endl;
}

#endif

// Класс Wine должен содержать метод GetBottles(), который для объекта Wine
// заданного возраста предлагает пользователю ввести соответствующие значения
// для года урожая и количества бутылок. Метод Label() должен возвращать ссылку
// на название вина, а метод sum() - общее количество бутылок во втором объекте
// valarray<int> из объекта Pair.

// Программа должна предлагать пользователю ввести название вина, количество
// элементов в массиве, а также год и количество бутылок для каждого элемента
// массива. Программа должна использовать эти данные для создания объекта
// Wine и вывода информации, хранимой в объекте. Для справки ниже приведен
// пример тестовой программы:

// // ре 14-1 . срр - класс Wine с использованием включения
// int main(void)
// {
//     using std::cin;
//     using std::cout;
//     using std::endl;
//     cout << "Enter name of wine: ";
//     char lab[50];
//     cin.getline(lab, 50);
//     // ввод названия вина
//     cout << "Enter number of years: ";
//     int yrs;
//     // ввод количества годов сбора винограда
//     cin >> yrs;
//     Wine holding(lab, yrs); // сохранение названия, лет, соэдание массивов из yrs элементов
//     holding.GetBottles();   // предложение ввести год и количество бутылок
//     holding.Show();         // вывод содержимого объекта
//     const int YRS = 3;
//     int y[YRS] = {1993, 1995, 1998};
//     int b[YRS] = {48, 60, 72};
//     // Создание нового объекта, инициализация с исполь зо6анием данных из масси6О6 y и b
//     Wine more("Gushing Grape Red", YRS, y, b);
//     more.Show();
//     cout << "Total bot tles for " << more.Label() // исполь зуется метод Label ()
//          << ": " << more.sum() << endl;           // используется метод sum ()
//     cout << "Bye\n";
//     return 0;
// }
// А так может выглядеп, вывод программы:

// Enter name of wine: Gully Wash
// Enter number of years: 4
// Enter Gully Wash data for 4 year(s):
// Enter year: 1988
// Enter bottles for that year: 42
// Enter year: 1994
// Enter bottles for that year: 58
// Enter year: 1998
// Enter bottles for that year: 122
// Enter year: 2001
// Enter bottles for that year: 144
// Wine: Gully Wash
//     Year    Bottles
//     1988    42
//     1994    58
//     1998    122
//     2001    144
// Total bottles for Gushing Grape Red: 180
// Вуе