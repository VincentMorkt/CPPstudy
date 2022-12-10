// 5. Ниже приведено несколько объявлений классов:
//  emp.h - - заголовочный файл для класса abstr_emp и его дочерних классов
#include <iostream>
#include <string>
class abstr_emp
{
private:
    std::string fname; // имя abstr _ emp
    std::string lname; // фамилия abstr_emp
    std::string job;

public:
    abstr_emp();
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const;                                          // выводит все данные с именами
    virtual void SetAll();                                                 // запрашивает значения у поль зователя
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &е); // Выводит только имя и фамилию
    virtual ~abstr_emp() = 0;                                              // виртуаль ный базовый класс
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string &fn, const std::string &ln, const std::string &j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof; // количество управляемых abst r_emp
protected:
    int InChargeOf() const { return inchargeof; } // вывод
    int &InChargeOf() { return inchargeof; }      // ввод
public:
    manager();
    manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0);
    manager(const abstr_emp &е, int ico);
    manager(const manager &m);
    virtual void ShowAll() const;
    virtual void SetAll();
};
class fink : virtual public abstr_emp
{
private:
    std::string reportsto; // кому выводить отчеты
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

public:
    fink();
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo);
    fink(const abstr_emp &е, const std::string &rpo);
    fink(const fink &е);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink // надзор за управляющими
{
public:
    highfink();
    highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico);
    highfink(const abstr_emp &е, const std::string &rpo, int ico);
    highfink(const fink &f, int ico);
    highfink(const manager &m, const std::string &rpo);
    highfink(const highfink &h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

// Здесь в иерархии классов используется множественное наследование с виртуальным базовым классом.
// Поэтому не забывайте о специальных правилах для списков инициализации в конструкторах.
// Обратите также внимание на наличие нескольких методов с защищенным доступом.
// Это упрощает код некоторых методов highfink.
// (Например, если метод highfink::ShowAll() просто вызывает fink::ShowAll())
// и manager::ShowAll(), то это приводит к двукратному вызову abstr_emp::ShowAll().)
// Реализуйте эти методы и протестируйте классы.

// Ниже приведена минимальная тестовая программа:

// ре 14-5 . срр
// useemp l . cpp - - исполь зование кла ссов abstr_emp
#include <iostream>
using namespace std;
#include "emp.h"
int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); // укомплектовано?
    hf.ShowAll();
    cout << "Press a key for next phase:\n"; // Нажать любую клавишу для следующей фазы
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using an abstr_emp * pointer:\n"; // Исполь зование указателя abstr_eтp *
    abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
    return 0;
}
// Почему не определена операция присваивания?
// Почему методы ShowAll() и SetAll() виртуальные?
// Почему класс abstr_emp является виртуальным базовым классом?
// Почему в классе highfink нет раздела данных?
// Почему достаточно только одной версии операции operator<<()?
// Что произойдет, если код в конце программы модифицировать следующим образом:

abstr_emp tri[4] = {em, fi, hf, hf2};
for (int i = 0; i < 4; i++)
    tri[i].ShowAll();