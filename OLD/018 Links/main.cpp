// тест использования ссылочных переменных

#include <iostream>
int main()
{
    using namespace std;
    int origin = 10;
    int *pOrigin = &origin;
    int &link = *pOrigin;   // ссылочная переменная link будет альтернативой origin, но не *pOrigin (хоть это сейчас кажется странным)
    cout << "origin = " << origin << endl
         << "*pOrigin = " << *pOrigin << endl
         << "&link = " << link << endl;
    int newOrigin = 20;
    origin = 15;
    pOrigin = &newOrigin;
        cout << "newOrigin = " << newOrigin << endl
         << "*pOrigin = " << *pOrigin << endl
         << "&link = " << link << endl;
         cin.get();
}