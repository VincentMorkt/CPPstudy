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
    birdsMarket *companies = new birdsMarket; // динамическое выделение памяти для структуры с помощью оператора new. сompanies - указатель структуру
    cout << "Enter birds diameter in mm: ";
    cin >> companies->diameterBird_mm; // для доступа к членам структуры использована операция членства через указатель ->
    cout << "Enter company name: ";
    cin.get(); // отсечение символа переноса строки
    getline(cin, companies->companyName);
    cout << "Enter bird weight in Kg: ";
    cin >> companies->weightBirdKg;
    cin.get();   // отсечение символа переноса строки
    cout << endl // вывод на экран значений, записанных в членах составной переменной типа структура
         << "Name of company: " << companies->companyName << endl
         << "Birds diametr in mm: " << companies->diameterBird_mm << endl
         << "Birds weight in kg: " << companies->weightBirdKg << endl;
    delete companies;
    cin.get();
    return 0;
}