// 4. Класс Person (Человек) предназначен для хранения имени и фамилии человека.
// Кроме конструкторов он содержит метод Show() для вывода этих данных.

// Класс Gunslinger (Снайпер) виртуально порожден от класса Person.
// Оп содержит член Draw(), который возвращает значение типа double - время,
// необходимое снайперу для перехода в боевую готовность.
// Класс также имеет член типа int, содержащий количество насечек на винтовке.
// И, наконец, класс содержит функцию Show(), которая выводит всю эту информацию.

// Класс PokerPlayer (Игрок в покер) виртуально порожден от класса Person. Он
// имеет метод Draw(), который возвращает случайное число в диапазоне от 1 до
// 52 - значение карты. (Можно создать класс Card с членами, определяющими
// масть и рубашку карты, чтобы метод Draw() возвращал значение типа Card.)
// Класс PokerPlayer использует функцию Show() класса Person.

// Класс BadDude (Хулиган) открыто порожден от классов Gunslinger и PokerPlayer.
// Он содержит член Gdraw(), возвращающий время вынимания оружия, и член Cdraw(),
// возвращающий следующую вытянутую карту. У него есть соответствующая функция Show().

// Определите все упомянутые классы и методы вместе с другими необходимыми методами
// (такими как методы для задания значений объекта) и протестируйте их с помощью
// простой программы, подобной представленной в листинге 14.12.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Persone
{
private:
    std::string fname;
    std::string sname;

protected:
    void pGet()
    {
        using namespace std;
        cout << "enter first name: ";
        getline(cin, fname);
        cout << "enter second name: ";
        getline(cin, sname);
    }
    void pShow() { std::cout << "name: " << fname << ' ' << sname << std::endl; }

public:
    Persone(const char *f = "empty first name", const char *s = "empty second name") : fname(f), sname(s) {}
    virtual void Show()
    {
        std::cout << "simple person\n";
        Persone::pShow();
    }
    virtual void Get() { Persone::pGet(); }
};

class Gunslinger : virtual public Persone
{
private:
    double time;   // время в секундах
    int headshots; // насечки на стволе
protected:
    void pGet()
    {
        using namespace std;
        cout << "enter prepare time: ";
        cin >> time;
        cin.get();
        cout << "enter headshots: ";
        cin >> headshots;
        cin.get();
    }
    void pShow() { std::cout << "prepare time: " << time << std::endl
                             << "headshots: " << headshots << std::endl; }

public:
    Gunslinger(double t = 0, int hs = 0, const char *f = "empty first name", const char *s = "empty second name")
        : Persone(f, s), time(t), headshots(hs) {}
    void Get()
    {
        Persone::pGet();
        Gunslinger::pGet();
    }
    void Show()
    {
        std::cout << "gunslinger\n";
        Persone::pShow();
        Gunslinger::pShow();
    }
    const double Draw() { return time; }
};

class Card // класс обозначающий карты
{
public:
    enum suits
    {
        none = 0,
        diamonds = 1,
        clubs = 2,
        hearts = 3,
        spades = 4
    };

private:
    const char *suitsNames[5] = {"none", "diamonds", "clubs", "hearts", "spades"};
    suits suit;
    int rank;

public:
    Card(suits s = none, int r = 0) : suit(s), rank(r % 14) {} // 13 карт и 0. при передаче 0 будет 0.
                                                               // при передаче 1 - 13 будет 1 - 13. при передаче 14 будет 0 и т.д.
    void random()
    {
        std::srand(time(0));
        suit = suits(rand() % 4 + 1);
        rank = rand() % 13 + 1;
    }
    friend std::ostream &operator<<(std::ostream &os, const Card &c)
    {
        os << c.suitsNames[(int)c.suit] << ", " << c.rank;
        return os;
    }
};

class PokerPlayer : virtual public Persone
{
private:
    Card card;

protected:
    void pShow()
    {
        std::cout << "card: " << card << std::endl;
    }

public:
    PokerPlayer(const char *f = "empty first name", const char *s = "empty second name") : Persone(f, s) { random(); } // random() функция член текущего класса
    const Card &Draw() { return card; }
    void random() { card.random(); } // вызывается функция член класса Card
    // переопределение функции Get не требуется, будет использована функция базового класса
    void Show() // в задании указано, что данный клас использует функцию Show базового класса.
                // Но это не имеет смысла, у нас есть интересный член данных, и нужно его показать.
                // Для целей изучения виртуальных функций подходит метод Get(), который можна взять с базового класса
                // Поскольку член данных устанавливается автоматически рандомным значением
    {
        std::cout << "poker player\n";
        Persone::pShow();
        PokerPlayer::pShow();
    }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(double t = 0, int hs = 0, const char *f = "empty first name", const char *s = "empty second name")
        : Persone(f, s), Gunslinger(t, hs, f, s), PokerPlayer(f, s) {}
    const double Gdraw() { return Gunslinger::Draw(); }
    const Card &Cdraw() { return PokerPlayer::Draw(); }
    void Get()
    {
        Persone::pGet();
        Gunslinger::pGet();
    }

    void Show()
    {
        std::cout << "bad dude\n";
        Persone::pShow();     // использована модульная система для управления вводом и отображением содержимого объектов
        Gunslinger::pShow();  // защищённые методы обеспечивают управление членами-данными соответствующего класса
        PokerPlayer::pShow(); // и позволяют собрать из них необходимый набор действий в производных классах
    }
};