// 3. Перепишите класс Stock, описанный в листингах 10.7 и 10.8 в главе 10,
// чтобы он использовал для хранения названий пакетов акций непосредственно динамически выделенную память,
// а не объекты класса string. Кроме того, замените функцию-член show() перегруженным определением operator<<().
// Протестируйте новое определение с помощью программы из листинга 10.9.

// stock20.h -- augmented version
#ifndef STOCK03_H_
#define STOCK03_H_
#include <string>
#include <iostream>

class Stock
{
private:
  // std::string company;
  char *company;
  int shares;
  double share_val;
  double total_val;
  void set_tot() { total_val = shares * share_val; }

public:
  //  Stock();        // default constructor
  Stock(const char *co, long n = 0, double pr = 0.0);
  Stock();
  Stock(const Stock &st);
  const Stock & operator=(const Stock & st);
  ~Stock(); // do-nothing destructor
  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);
  // void show()const;
  const Stock &topval(const Stock &s) const;
  friend std::ostream &operator<<(std::ostream &os, const Stock &st);
};

#endif
