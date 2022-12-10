// 3. Перепишите класс Stock, описанный в листингах 10.7 и 10.8 в главе 10,
// чтобы он использовал для хранения названий пакетов акций непосредственно динамически выделенную память,
// а не объекты класса string. Кроме того, замените функцию-член show() перегруженным определением operator<<().
// Протестируйте новое определение с помощью программы из листинга 10.9.

// stock20.cpp -- augmented version
#include <iostream>
#include <cstring>
#include "stock03.h"
using namespace std;
// constructors
Stock::Stock() // default constructor
{
    company = new char[1];
    company[0] = 0;
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr)
{
    company = new char[strlen(co) + 1];
    strcpy(company, co);

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock() // quiet class destructor
{
    delete[] company;
}

Stock::Stock(const Stock &st)
{
    company = new char[strlen(st.company) + 1];
    strcpy(company, st.company);
    share_val = st.share_val;
    total_val = st.total_val;
    shares = st.shares;
}

const Stock &Stock::operator=(const Stock &st)
{
    if (this == &st)
        return *this;
    delete[] company;
    company = new char[strlen(st.company) + 1];
    strcpy(company, st.company);
    share_val = st.share_val;
    total_val = st.total_val;
    shares = st.shares;
    return *this;
}

// other methods
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

// void Stock::show() const
std::ostream &operator<<(std::ostream &os, const Stock &st)
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << st.company
         << "  Shares: " << st.shares << '\n';
    cout << "  Share Price: $" << st.share_val;
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << st.total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
    return os;
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
