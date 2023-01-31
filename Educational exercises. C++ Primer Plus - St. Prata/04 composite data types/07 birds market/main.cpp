/*Вильям Вингейт (William Wingate) заведует службой анализа рынка пиццы. О каждой пицце он записывает следующую информацию:
• наименование компании - производителя пиццы, которое может состоять
из более чем одного слова;
• диаметр пиццы;
• вес пиццы.
Разработайте структуру, которая может содержать всю эту информацию, и напишите программу, использующую структурную переменную этого типа.
Программа должна запрашивать у пользователя каждый из перечисленных показателей и затем отображать введенную информацию. Применяйте cin
(или его методы) и cout.*/

#include <iostream>
#include <string>
struct birdsMarket // Объявлении структуры
{
    std::string companyName; // Члены структуры
    float diameterBird_mm;
    float weightBirdKg;
};
int main()
{
    using namespace std;
    birdsMarket companies;
    cout << "Enter company name: ";
    getline(cin, companies.companyName); // функция getline() для работы с объектами string. Позволяет вводить с клавиатуры названия, состоящие из нескольких слов (допускает пробелы)
    cout << "Enter birds diameter in mm: ";
    cin >> companies.diameterBird_mm;
    cout << "Enter bird weight in Kg: ";
    cin >> companies.weightBirdKg;
    cin.get();   // отсечение символа переноса строки
    cout << endl // вывод на экран значений, записанных в членах составной переменной типа структура
         << "Name of company: " << companies.companyName << endl
         << "Birds diametr in mm: " << companies.diameterBird_mm << endl
         << "Birds weight in kg: " << companies.weightBirdKg << endl;
    cin.get();
    return 0;
}