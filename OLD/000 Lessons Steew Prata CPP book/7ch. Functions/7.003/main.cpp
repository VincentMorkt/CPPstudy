#include <iostream>
//Пусrь имеется следующее объявление структуры:
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
// а. Напишите функцию, принимающую структуру bох по значению и отображающую все ее члены.
// б. Напишите функцию, принимающую адрес структуры bох и устанавливающую значение члена volume равным произведению остальных трех членов.
// в. Напишите простую программу, которая использует эти две функции.

void FunctCin(box *name); // прототипы фунеций
void FunctPrint(box name);
void FunctEdit(box *name);

int main()
{
    box name;                                 // объявление переменной структуры
    FunctCin(&name);                          // вызов функции ввода
    FunctPrint(name);                         // вызов функции вывода
    std::cout << "\nPress <ENTER> to close."; // закрытие программы
    std::cin.get();                           // ожидание ввода для просмотра результатов работы программы
    return 0;
}

void FunctCin(box *structName) // функция ввода, принимает адресс структуры для работы с оригинальными данными
{
    using std::cin;
    using std::cout;
    cout << "Enter maker: ";
    cin.getline(structName->maker, 40); // ввод значений в переменные-члены структуры через операцию косвенного членства
    cout << "Enter height: ";
    cin >> structName->height;
    cin.get();
    cout << "Enter width: ";
    cin >> structName->width;
    cin.get();
    cout << "Enter lenght: ";
    cin >> structName->length;
    cin.get();
    cout << std::endl;
    FunctEdit(structName); // вызов функции вычисляющей объём. structName является указателем, поэтому операция & не требуется
    return;
}
void FunctEdit(box *structName) // функция, вычисляющая объём. принимает адресс переменной структуры для работы с оригинальными данными
{
    structName->volume = structName->height * structName->width * structName->length;
}
void FunctPrint(box structName) // функция вывода, принимает структуру по значению и работает с копиями данных
{
    using std::cout;
    using std::endl;
    cout << "Maker: " << structName.maker << endl
         << "Height: " << structName.height << endl
         << "Width: " << structName.width << endl
         << "Lenght: " << structName.length << endl
         << "Volume: " << structName.volume << endl;
}