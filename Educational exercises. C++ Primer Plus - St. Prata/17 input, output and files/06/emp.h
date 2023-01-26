// 5. Ниже приведено несколько объявлений классов:
//  emp.h - - заголовочный файл для класса abstr_emp и его дочерних классов
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

enum classkind
{
    Employee,
    Manager,
    Fink,
    Highfink
};
using namespace std;
std::map<classkind, std::string> classnames = {{Employee, "--Employee--"},
                                               {Manager, "--Manager--"},
                                               {Fink, "--Fink--"},
                                               {Highfink, "--Highfink--"}};

//////////////////////

classkind getChoice(std::string str) // возвращает ключ classkind, соответствующий переданой строке.
{                                    // Если ключ не найден, сообщает об ошибке и завершает программу.
    classkind choice = (classkind)0;
    while (str != classnames[choice])
    {
        choice = (classkind)(choice + 1);
        if (choice > Highfink)
        {
            cerr << "getChoice error, argumetn is not classnames\n";
            exit(EXIT_FAILURE);
        }
    }
    return choice;
}

    //////////////////////
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
        virtual void WriteToFile(std::ofstream &fs) const;                      // записывает данные в файл
        virtual void ReadFromFile(std::ifstream &fs);                           // читает данные из файла
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
    void abstr_emp::WriteToFile(std::ofstream & fs) const
    {
        fs << fname << ' ' << lname << endl
           << job << endl;
    }
    void abstr_emp::ReadFromFile(std::ifstream & fs)
    {
        fs >> fname >> lname >> job;
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
        void ShowAll() const
        {
            std::cout << "category employee\n";
            abstr_emp::ShowAll();
        }
        void SetAll() { abstr_emp::SetAll(); }
        void WriteToFile(std::ofstream &fs) const;
        void ReadFromFile(std::ifstream &fs) { abstr_emp::ReadFromFile(fs); }
    };

    void employee::WriteToFile(std::ofstream & fs) const
    {
        fs << classnames[Employee] << endl; // запишет в файл 0, позже этот 0 будет прочитан как classkind::Employee
        abstr_emp::WriteToFile(fs);
    }

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
        void ShowAll() const;
        void SetAll();
        void WriteToFile(std::ofstream &fs) const; // записывает данные в файл
        void ReadFromFile(std::ifstream &fs);
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
    void manager::WriteToFile(std::ofstream & fs) const
    {
        fs << classnames[Manager] << endl;
        abstr_emp::WriteToFile(fs);
        fs << inchargeof << endl;
    }
    void manager::ReadFromFile(std::ifstream & fs)
    {
        abstr_emp::ReadFromFile(fs);
        fs >> inchargeof;
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
        void ShowAll() const;
        void SetAll();
        void WriteToFile(std::ofstream &fs) const; // записывает данные в файл
        void ReadFromFile(std::ifstream &fs);      // читает данные с файла
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
    void fink::WriteToFile(std::ofstream & fs) const
    {
        fs << classnames[Fink] << endl;
        abstr_emp::WriteToFile(fs);
        fs << reportsto << endl;
    }
    void fink::ReadFromFile(std::ifstream & fs)
    {
        abstr_emp::ReadFromFile(fs);
        fs >> reportsto;
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
        void ShowAll() const;
        void SetAll();
        void WriteToFile(std::ofstream &fs) const; // записывает данные в файл
        void ReadFromFile(std::ifstream &fs);      // читает данные с файла
    };

    void highfink::ShowAll() const
    {
        std::cout << "category highfink\n";
        abstr_emp::ShowAll();
        std::cout << "In charge of: " << InChargeOf() << std::endl
                  << "Reports to: " << ReportsTo() << std::endl;
    }
    void highfink::SetAll()
    {
        using namespace std;
        abstr_emp::SetAll();
        std::cout << "Enter number in charge of: ";
        std::cin >> InChargeOf();
        std::cout << "Enter reports to: ";
        getline(std::cin, ReportsTo());
    }
    void highfink::WriteToFile(std::ofstream & fs) const
    {
        fs << classnames[Highfink] << endl;
        abstr_emp::WriteToFile(fs);
        fs << InChargeOf() << endl
           << ReportsTo() << endl;
    }
    void highfink::ReadFromFile(std::ifstream & fs)
    {
        abstr_emp::ReadFromFile(fs);
        fs >> InChargeOf();
        getline(fs, ReportsTo());
    }

