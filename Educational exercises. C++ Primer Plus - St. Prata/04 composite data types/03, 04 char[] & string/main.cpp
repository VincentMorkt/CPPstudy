/*3. Напишите программу, которая запрашивает у пользователя имя, фамилию, а затем конструирует,
сохраняет и отображает третью строку, состоящую из фамилии пользователя, за которой следует запятая,
пробел и его имя. Используйте массивы char и функции из заголовочного файла cstring.
Пример запуска должен выглядеть так:
Enter your first name: Flip
Enter your last name: Fleminq
Here's the in formation in аs ingle string: Fleming, Flip*/

#include <iostream>
#include <string>
int main()
{
    /*using namespace std;
    cout << "Enter your first name: ";
    const int Num = 20;
    char firstName[Num];
    cin >> firstName;
    cout << "Enter your last name: ";
    char lastName[Num];
    cin >> lastName;
    cin.get();
    cout << "Here's the in formation in as ingle string: " <<lastName <<", " <<firstName;
    cin.get();
    return 0;*/

/* 4. Напишите аналогичную программу, которая приглашает пользователя ввести его имя и фамилию, 
а затем построит, сохранит и отобразит третью строку, состоящую из фамилии,
за которой следует запятая, пробел и имя. Используйте объекты string и методы 
из заголовочного файла string.*/

    using namespace std;
    cout << "Enter your first name: ";
    string firstName;
    cin >> firstName;
    cout << "Enter your last name: ";
    string lastName;
    cin >> lastName;
    cin.get();
    cout << "Here's the in formation in as ingle string: " << lastName << ", " << firstName;
    cin.get();
}
