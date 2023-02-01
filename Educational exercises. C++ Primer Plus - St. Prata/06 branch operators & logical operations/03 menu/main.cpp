/*. Напишите предшественник программы, управляемой меню. Она должна отображать меню из четырех пунктов, каждый из них помечен буквой. 
Если пользователь вводит букву, отличающуюся от четырех допустимых, программа должна повторно приглашать его ввести правильное значение до тех пор, 
пока он этого не сделает. Затем она должна выполнить некоторое простое действие на основе пользовательского выбора. Работа программы должна выглядеть примерно так:

Please enter оnе of the following choices :
с) carnivore р) pianist
t) tree g) game
f
Please enter а с, р, t, or g: q
Please enter а с, р, t, or g: t
А maple is а tree . 
*/

#include <iostream>
#include <cctype>

int main ()
{
    using namespace std;
    const char*weapon [4] = // объявление массива указателей на char. Просто для удобства
    {                       // инициализация этого массива
        {"a) M109"},
        {"b) CAESAR"},
        {"c) Archer"},
        {"d) AHS Krab"}
    };
    char ch;                // объявление переменной char для маршрутизации switch вводимым значением
    cout << "\tPlease, choose a weapon: \n\n"
    << weapon[0] << "\t\t"<< weapon[1] << "\n"<< weapon[2] << "\t"<< weapon[3] << "\n\n"; // это можно сделать через цикл, но с таким количеством пунктов нет смысла морочится 
    // цикл для повторного ввода в случае некорректного ввода
    while(cin.get(ch)) // пока ввод удачен. присвоить вводимое значение переменной ch
        {
            if(!isalnum(ch))// если вводимый символ не буква или цифра
                continue;   // начать новый цикл. отбрасывает пробельные символы, знаки препинания (вроде -а) и т.д. 
            switch (ch)     // объявление оператора switch с выражением (ch)
            {
                case 'A':   // маршрутизация осуществляется как по заглавной, так и по строчной буквам
                case 'a': cout << "\nYou chose: " <<weapon [0] <<"! Rusni pizda within a radius of 22 km.\n";
                    break;  // прерывание оператора switch
                case 'B':
                case 'b': cout << "\nYou chose: " <<weapon [1] <<"! Rusni pizda within a radius of 41 km.\n";
                    break;
                case 'C':
                case 'c': cout << "\nYou chose: " <<weapon [2] <<"! Rusni pizda within a radius of 32 km.\n";
                    break;
                case 'D':
                case 'd': cout << "\nYou chose: " <<weapon [3] <<"! Rusni pizda within a radius of 30 km.\n";
                    break;
                default:                        // в случае, если введён несоответствующий перечисленным case символ
                    while (cin.get() != '\n')   // очистка потока ввода включительно с \n (остановив вложенный цикл после прочтения \n)
                        continue;               // относится к внутреннему циклу
                    cout << "Please, enter only a, b, c or d:\n";   // подскаска пользователю
            continue;   // относится к внешнему циклу. Начать новый цикл для повторной попытки ввода
            }
            break;  // если было введено корректное значение, оператор continue будет пропущен, и программа выполнит оператор break; завершив выполнение внешнего цикла
        }
    while (cin.get() != '\n') // очистка потока ввода
        continue;
    // завершение программы
    cout <<"\nPress <ENTER> to close\n";
    cin.get();
    return 0;
}