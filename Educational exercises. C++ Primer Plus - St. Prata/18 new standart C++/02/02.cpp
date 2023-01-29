// 2. Ниже показано объявление класса Cpmv: 
class Cpmv
{
public:
    struct Info
        std::string qcode;
    std::string zcode;

private:
    Info *pi;

public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv &ep);
    Cpmv(Cpmv &&mv);
    ~Cpmv();
    Cpmv &operator=(const Cpmv &ep);
    Cpmv &operator=(Cpmv &&mv);
    Cpmv operator+(const Cpmv &obj) const;
    void Display() const;
};
// Функция operator+ () должна создавать объект, члены qcode и zcode которого 
// являются результатом конкатенации соответствующих членов операндов.
// Напишите код, который реализует семантику переноса для конструктора переноса 
// и операции присваивания с переносом. Напишите программу, использующую все методы класса Cpmv. 
// В целях тестирования обеспечьте выдачу сообщений в методах, 
// чтобы можно было увидеть, когда они используются. 