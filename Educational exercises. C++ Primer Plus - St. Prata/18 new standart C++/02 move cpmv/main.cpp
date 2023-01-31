#include "cpmv.h"
// программа демонстратор класса Cmpv, содержащего конструкторы и операции переноса

int main()
{
    using namespace std;
    // методы вызываются последовательно согласно их объявлениям в классе.
    // все методы снабжены информационными сообщениями, поэтому дополнительное отображение данных и адресов не требуется

    // конструктор по умолчанию
    cout << "constructor deafult: Cpmv cpmv1;\n";
    Cpmv cpmv1;

    // конструктор(string, string)
    cout << "constructor (string, string): Cpmv cpmv2(\"qwerty\", \"abcd\");\n";
    Cpmv cpmv2("qwerty", "abcd");

    // конструктор копирования
    cout << "constructor copy: Cpmv cpmv3(cpmv2);\n";
    Cpmv cpmv3(cpmv2);

    // конструктор копирования переносом
    // для вызова конструктора необходим rvalue объект
    // для его создания используем определённую в классе операцию конкатенации
    cout << "constructor move: Cpmv cpmv4(cpmv2 + cpmv1);\n";
    Cpmv cpmv4(cpmv2 + cpmv1); // оператор + вернёт временный анонимный объект класса, адрес которого будет уникальным

    // операция присваивания
    cout << "operator=(Cpmv&): cpmv1 = cpmv4;\n";
    cpmv1 = cpmv4;

    // операция присваивания переносом
    cout << "operator=(Cpmv&&): cpmv1 = cpmv1 + cpmv4;\n";
    cpmv1 = cpmv1 + cpmv4;

    cin.get();
    return 0;
}