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
#include <cstring>
#include "BadDude.h"

const int SIZE = 5;

int main()
{
    using namespace std;
    Persone *lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the persone category: \n"
             << "s: simple persone  g: gunslinger\n"
             << "p: pocker player   b: bad dude\n"
             << "q: quit\n";
        cin >> choice;
        while (strchr("sgpbq", choice) == nullptr)
        {
            cout << "Please enter а s, g, p, b, or q: ";
            cin >> choice;
        }
        cin.get();
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 's':
            lolas[ct] = new Persone;
            break;
        case 'g':
            lolas[ct] = new Gunslinger;
            break;
        case 'p':
            lolas[ct] = new PokerPlayer;
            break;
        case 'b':
            lolas[ct] = new BadDude;
            break;
        }
        lolas[ct]->Get();
        cout << endl;
    }
    cout << "\nHere is your team:\n\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        lolas[i]->Show();
        cout << endl;
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
    cin.get();
    return 0;
}