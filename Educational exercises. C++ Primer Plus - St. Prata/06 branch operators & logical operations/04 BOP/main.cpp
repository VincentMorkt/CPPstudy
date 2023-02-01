/*Когда вы вступите в Благотворительный Орден Программистов (БОП) , к вам могут обращаться на заседаниях БОП по вашему реальному имени, по должности либо секретному имени БОП.
Напишите программу, которая может выводить списки членов по реальным именам, должностям, секретным именам либо по предпочтению самого члена. В основу положите следующую структуру:
11 Структура имен Благотворительного Ордена Программистов (БОП)

struct bор
{
char fullname [strsize] ;   // реальное имя
char title [strsize] ;      // должность
char bopname [strsize] ;    // секретное имя БОП
int preference;             // 0 = полное имя , 1 = титул , 2 = имя БОП
};

В этой программе создайте небольшой массив таких структур и инициализируйте его соответствующими значениями. Пусть программа запустит цикл, который даст возможность пользователю выбирать разные альтернативы:

а. display Ьу name Ь. display Ьу ti tle
с. display Ьу bopname d. display Ьу preference
q. quit

Обратите внимание, что "display bу preference" (отображать по предпочтениям) не означает, что нужно отобразить член prefe rence; это значит, что необходимо отобразить член структуры,
который соответствует значению pre ference. Например, если prefe rence равно 1, то выбор d должен вызвать отображение должности данного программиста.
Пример запуска этой программы может выглядеть следующим образом:

Benevolent Orderof Programmers Report

а. display bу name      b. display Ьу title
с. display Ьу bopname   d. display Ьу preference
q. quit

Enter your choice: а

Wimp Macho
Raki Rhodes
Celia Lai ter
Норру Hipman
Pat Hand

Next choice : d

Wimp Macho
Jun ior Programmer
MIPS
Analyst Trainee
LOOPY

Next choice : q

Вуе!
*/

#include <iostream>
#include <cctype>
#include <ctime>

const int StrSize = 40;
const int Num = 5;
struct bop
{
    char fullName[StrSize]; // реальное имя
    char titel[StrSize];    // должность
    char bopName[StrSize];  // секретное имя БОП
    int preference;         // 0 = полное имя, 1 = должность, 2 = имя БОП
};
bop members[Num] = // объявление и инициализация массива структур
    {
        {"Stepan Rudko", "Idea leader", "Bandera", 2},
        {"Oleg Fisko", "Analyst", "Check", 1},
        {"Victor Skyrda", "Chirlider", "Shibaygolowa", 1},
        {"Dmytro Gustosmyl", "Connector", "Radar", 2},
        {"Adriyan Vyshezir", "Leader", "Example", 0}};

int main()
{
    using namespace std;

    cout << "Display by:\n\n"
            "a) name \t b) title\n"
            "c) bopname \t d) preference\n"
            "q) quit\n\n"
            "Enter you choise: ";

// ядро программы /////////////////////////////////////////////////////////////////

    char ch;
    while (cin.get(ch))   // проверочное условие присваивает вводимое значение переменной ch и проверяет удачность ввода
    {
        if (!isalnum(ch)) // если вводимый символ не буква или цифра
            continue;     // начать новый цикл (защита от ввода -a, /a или пробелов перед символами)
        cout << endl;
        switch (ch) // оператор switch
        {
        case 'A': // первые шесть case (A,a,B,b,C,c) выполняют вывод на экран списка содержания переменных массива структур
        case 'a':
            for (int i = 0; i < Num; i++) // цикл для вывода на экран переменной .fullName массива структур members[] 
                cout << members[i].fullName << endl; 
            break;
        case 'B':
        case 'b':
            for (int i = 0; i < Num; i++)
                cout << members[i].titel << endl;
            break;
        case 'C':
        case 'c':
            for (int i = 0; i < Num; i++)
                cout << members[i].bopName << endl;
            break;
        case 'D': // case 'd' содержит встроенный оператор switch
        case 'd':
            for (int i = 0; i < Num; i++)
                switch (members[i].preference) // выражением служит перменная структуры
                {
                case 0: // переменная .preference отражает то, какая из переменных структуры будет выведена на экран
                    cout << members[i].fullName << endl;
                    break;
                case 1:
                    cout << members[i].titel << endl;
                    break;
                case 2:
                    cout << members[i].bopName << endl;
                    break;
                }
            break; // завершение case 'd'
        case 'Q':
        case 'q':
            cout << "Bye!\n";         // case 'q' выводит прощальное сообщение и запускает цикл задержки перед закрытием программы
            break;                    // относится к case 'q'
        default:                      // в случае, если введён несоответствующий перечисленным case символ
            while (cin.get() != '\n') // очистка потока ввода
                continue;
            cout << "Please, enter only a, b, c, d or q to quit: ";
            continue; // относится к внешнему циклу. Начать новый цикл для повторной попытки ввода
        }
        if (ch == 'q' || ch == 'Q') // если  сh == 'q' или 'Q' прервать внешний цикл (что приводит к завершению программы)
            break;
        while (cin.get() != '\n') // если цикл не прерван - очистка очереди потока ввода
            continue;
        cout << "\nNext choice: "; // предложение повторного ввода
    }
    
    // завершение программы /////////////////////////////////////////////////////////////////////////////
    
                                        // цикл задержки, оставляющий открытым окно программы в течении двух секунд после вывода прощального сообщения
    clock_t delay = 2 * CLOCKS_PER_SEC; // clock_t - псевдоним типа данных, соответствующего типу возвращаемых данных функции clock() (он отличается в разных системах).
                                        // Константа CLOCKS_PER_SEC соответствует количеству единиц системного времени в секунду.
                                        // выражение clock_t(2 * CLOCKS_PER_SEC) означает "2 секунды"
    clock_t start = clock();            // функция clock() возвращает системное время, прошедшее с момента запуска программы в единицах системного времени
    while (clock() - start < delay)     // проверочное условие цикла задержки (время прошедшее с момента запуска программы - время выполнения предыдущего оператора < заданной задержки)
        continue;
    return 0;
}
