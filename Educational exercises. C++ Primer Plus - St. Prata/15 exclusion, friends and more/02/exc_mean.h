// 2. Измените код в листинге 15.11 так, чтобы два типа исключений были классами,
// производными от класса logic_error, определенного в заголовочном файле <stdexcept>.
// Сделайте так, чтобы каждый метод what() сообщал имя функции и суть проблемы.
// Объекты исключений не должны содержать значение ошибки,
// они должны просто поддерживать метод what().

// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>
#include <cstring>

class my_err : public std::logic_error
{
private:
    std::string function_name;
    std::string massege;

public:
    my_err(const char *ch = "ERROR! unknow logic_error", const std::string funct_name = "unknow function")
        : std::logic_error(ch), function_name(funct_name){};
    virtual ~my_err() = 0;
    virtual const char *what();
};

my_err::~my_err() {}

const char *my_err::what()
{
    using std::string;
    massege = string(std::logic_error::what()) + "\nlocation: " + function_name + "\n"; // формирование общего сообщения
    return massege.c_str(); // преобразование в const char * для соответствия прототипу
}

class bad_hmean : public my_err
{
private:
    std::string function_name;

public:
    bad_hmean(const char *funct_name)
        : my_err("ERROR!\ninvalid arguments: a = -b", funct_name) {}
};

class bad_gmean : public my_err
{
private:
    std::string function_name;

public:
    bad_gmean(const char *funct_name)
        : my_err("ERROR!\ngmeans() arguments should be >= 0", funct_name) {}
};
