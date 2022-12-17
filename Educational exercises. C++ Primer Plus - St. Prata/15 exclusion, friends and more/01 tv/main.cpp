// 1 . Измените классы Tv и Remote, как описано ниже.

// а. Сделайте их взаимными друзьями.
// б. Добавьте в класс Remote переменную-член, описывающую режим пульта дистанционного управления - нормальный или интерактивный.
// в. Добавьте метод Remote, который отображает режим.
// г. Добавьте в класс Tv метод для переключения нового члена Remote. Этот метод должен работать, только если телевизор включен.

// main.cpp -- Напишите небольшую программу для тестирования новых возможностей.

#include <iostream>
#include "tv.h"

int main()
{
    using namespace std;
    cout << "Tv and Remote classes test\n\n"
         << "tv22 create:\n";
    Tv tv22;
    tv22.settings();
    cout << "\ntv22 methods:\n"
         << "onoff\n";
    tv22.onoff();
    tv22.settings();

    cout << "\nvolup /twice/, voldown, chanup /twice/, chandown, set_mode, set_input\n";
    tv22.volup();
    tv22.volup();
    tv22.voldown();
    tv22.chanup();
    tv22.chanup();
    tv22.chandown();
    tv22.set_mode();
    tv22.set_input();
    tv22.settings();

    cout << "\nremote1 create\n"
         << "remote1 methods:\n"
         << "showState\n";
    Remote remote1;
    remote1.show_state();

    cout << "\ntv22.set_remote, remote1.showState\n";
    tv22.set_remote(remote1);
    remote1.show_state();

    cout << "\nremote1.volup(tv22) /twice/, voldown(tv22), set_chan(22),\n"
         << "chanup(tv22) /twice/, chandown(tv22), set_mode(tv22), set_input(tv22)\n";
    tv22.settings();
    cout << "\nremote1.onoff(tv22)\n";
    tv22.settings();

    cin.get();
    return 0;
}