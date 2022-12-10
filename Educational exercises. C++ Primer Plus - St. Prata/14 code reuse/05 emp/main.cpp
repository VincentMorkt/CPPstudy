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
    cin.get();
    return 0;
}