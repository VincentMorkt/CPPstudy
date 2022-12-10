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
    abstr_emp() : fname("empty first name"), lname("empty last name"), job("none") {}
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j)
        : fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const;                                          // выводит все данные с именами
    virtual void SetAll();                                                 // запрашивает значения у пользователя
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e); // Выводит только имя и фамилию
    virtual ~abstr_emp() = 0;                                              // виртуальный базовый класс
};

void abstr_emp::ShowAll() const
{
    std::cout << "Name: " << fname << ' ' << lname << std::endl
              << "Job: " << job << std::endl;
}

void abstr_emp::SetAll()
{
    using namespace std;
    cout << "Enter first name: ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
    cout << "Enter job: ";
    getline(cin, job);
}

std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << e.lname << ", " << e.fname;
    return os;
}

abstr_emp::~abstr_emp() {}

//////////////////////////////////

class employee : public abstr_emp
{
public:
    employee() : abstr_emp() {}
    employee(const std::string &fn, const std::string &ln, const std::string &j)
        : abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const
    {
        std::cout << "category employee\n";
        abstr_emp::ShowAll();
    }
    virtual void SetAll() { abstr_emp::SetAll(); }
};

/////////////////////////////////

class manager : virtual public abstr_emp
{
private:
    int inchargeof; // количество управляемых abstr_emp
protected:
    int InChargeOf() const { return inchargeof; } // вывод
    int &InChargeOf() { return inchargeof; }      // ввод
public:
    manager() : abstr_emp(), inchargeof(0) {}
    manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0)
        : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp &e, int ico)
        : abstr_emp(e), inchargeof(ico) {}
    // manager(const manager &m); // зачем нам конструктор копирования? чем нам не подходит поверхностное копирование?
    virtual void ShowAll() const;
    virtual void SetAll();
};

void manager::ShowAll() const
{
    std::cout << "category manager\n";
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << inchargeof << std::endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter number in charge of: ";
    std::cin >> inchargeof;
    while (std::cin.get() != '\n')
        continue;
}

/////////////////////////////////

class fink : virtual public abstr_emp
{
private:
    std::string reportsto; // кому выводить отчеты
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

public:
    fink() : abstr_emp(), reportsto("none") {}
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp &e, const std::string &rpo)
        : abstr_emp(e), reportsto(rpo) {}
    // fink(const fink &e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

void fink::ShowAll() const
{
    std::cout << "category fink\n";
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << reportsto;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter reports to: ";
    getline(std::cin, reportsto);
}

///////////////////////////////

class highfink : public manager, public fink // надзор за управляющими
{
public:
    highfink()
        : abstr_emp(), manager(), fink() {}
    highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico)
        : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
    highfink(const abstr_emp &e, const std::string &rpo, int ico)
        : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
    highfink(const fink &c, int ico)
        : abstr_emp(c), manager(c, ico), fink(c) {}
    highfink(const manager &m, const std::string &rpo)
        : abstr_emp(m), manager(m), fink(m, rpo) {}
    // highfink(const highfink &h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

void highfink::ShowAll() const
{
    std::cout << "category highfink\n";
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << InChargeOf() << std::endl
              << "Reports to: " << ReportsTo() << std::endl;
}

void  highfink::SetAll()
{
    using namespace std;
    abstr_emp::SetAll();
    std::cout << "Enter number in charge of: ";
    std::cin >> InChargeOf();
    std::cout << "Enter reports to: ";
    getline(std::cin, ReportsTo());
}

// Здесь в иерархии классов используется множественное наследование с виртуальным базовым классом.
// Поэтому не забывайте о специальных правилах для списков инициализации в конструкторах.
// Обратите также внимание на наличие нескольких методов с защищенным доступом.
// Это упрощает код некоторых методов highfink.
// (Например, если метод highfink::ShowAll() просто вызывает fink::ShowAll())
// и manager::ShowAll(), то это приводит к двукратному вызову abstr_emp::ShowAll().)
// Реализуйте эти методы и протестируйте классы.

// Ниже приведена минимальная тестовая программа:

// ре 14-5 . срр
// // useemp l . cpp - - исполь зование кла ссов abstr_emp
// #include <iostream>
// using namespace std;
// #include "emp.h"
// int main(void)
// {
//     employee em("Trip", "Harris", "Thumper");
//     cout << em << endl;
//     em.ShowAll();
//     manager ma("Amorphia", "Spindragon", "Nuancer", 5);
//     cout << ma << endl;
//     mа.ShowAll();
//     fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
//     cout << fi << endl;
//     fi.ShowAll();
//     highfink hf(ma, "Curly Kew"); // укомплектовано?
//     hf.ShowAll();
//     cout << "Press а key for next phase:\n"; // Нажать любую клавишу для следующей фазы
//     cin.get();
//     highfink hf2;
//     hf2.SetAll();

//     cout << "Using an abstr_emp * pointer:\n"; // Исполь зование указателя abstr_eтp *
//     abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
//     for (int i = 0; i < 4; i++)
//         tri[i]->ShowAll();
//     return 0;
// }
// Почему не определена операция присваивания? -- автоматическа операция присваивания подходит
// Почему методы ShowAll() и SetAll() виртуальные? -- для корректной работы методов при обращении к объектам через указатель на базовый класс
// Почему класс abstr_emp является виртуальным базовым классом? -- отичный вопрос. он мог бы быть не виртуальным, и тогда класс employee не понадобился бы
// -- вероятно это полезно для защиты данных или ещё каких-то целей, в данный момент это необходимо для обучения.
// Почему в классе highfink нет раздела данных? -- потому что он не добавляет новых характеристик, а лишь объединяет в одном объекте данные родительских классов из разных веток
// Почему достаточно только одной версии операции operator<<()? -- она выводит только данные базового класса
// Что произойдет, если код в конце программы модифицировать следующим образом: -- мы объявляем массив объектов виртуального базового класса
// -- создавать такие объекты запрещено, поэтому мы получим ошибку. если бы класс не был виртуальным иобъекты можно было создать,
// -- то операция присваивания приняла бы ссылку на объекты производных классов, но присвоила бы только базовую часть.

// abstr_emp tri[4] = {em, fi, hf, hf2};
// for (int i = 0; i < 4; i++)
//     tri[i].ShowAll();