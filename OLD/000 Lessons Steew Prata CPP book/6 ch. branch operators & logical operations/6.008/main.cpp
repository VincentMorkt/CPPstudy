// Напишите программу, которая открывает текстовый файл , читает его символ за символом до самого конца и сообщает количество символов в файле.

#include <iostream>
#include <fstream> // файловый ввод-вывод
#include <ctime>
int main()
{
    using namespace std;

    // работа с данными ////////////////////////////////////////////////////

    ifstream inFile;   // объявление переменной обїекта ifstream
    char fileName[30]; // создание символьного массива для ввода имени файла. метод .open требует строк в стиле С.
    cout << "Enter the file name in the format name.txt: ";
    cin >> fileName;
    cin.get();

    // открытие файла и проверка успешности открытия ////////////////////////

    inFile.open(fileName); // открытие файла для работы с ним
    if (!inFile.is_open()) // проверка открытия файла
    {
        cout << "OPEN FAILURE! Maybe try name.txt.txt"; // сообщение об ошибке
        clock_t delay = 2 * CLOCKS_PER_SEC;             // задержка в 2 секунды
        clock_t start = clock();
        while (clock() - start < delay) // таймер задержки
            continue;
        exit(EXIT_FAILURE); // закрытие программы

    // ядро программы. подсчёт символов /////////////////////////////////////

    }
    int i = 0; // переменная для подсчёта символов 
    while (inFile.good())   // пока ввод успешн и не достигнут EOF
    {
        inFile.get();       // чтение символа
        i++;                // инкремент счётчика
    }
    cout << "File contains " << i << " characters\n";

    // закрытие программы ////////////////////////////////////////////////////

    cout << "\nPress <ENTER> to close.";
    cin.get(); // ожидание ввода для просмотра результатов работы программы
    return 0;
}