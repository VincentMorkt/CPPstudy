// 4. Напишите программу, которая открывает два текстовых файла для ввода и
// один для вывода. Программа должна соединять соответствующие строки входных файлов,
// используя в качестве разделителя пробел, и записывать результаты в выходной файл.
// Если один файл короче второго, остальные строки более
// длинного файла также должны копироваться в выходной файл.
// Например, предположим, что первый входной файл имеет следующее содержимое:
// eggs kites donuts
// balloons hammers
// stones
// А второй файл - такое:
// zero lassitude
// finance drama
// Результирующий файл должен выглядеть следующим образом:
// eggs kites donuts zero lassitude
// balloons hammers finance drama
// stones

#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    if (argc != 4)
    {
        cerr << "Incorect numbers of file names. Enter three file names: " << argv[0] << " name_from1 name_from2 name_to";
        exit(EXIT_FAILURE);
    }

    ifstream fin1(argv[1]);
    if (!fin1.is_open())
    {
        cerr << "First file dosent exist!";
        exit(EXIT_FAILURE);
    }

    ifstream fin2(argv[2]);
    if (!fin2.is_open())
    {
        cerr << "Second file dosent exist!";
        exit(EXIT_FAILURE);
    }

    ifstream check(argv[3]);
    if (check.is_open())
    {
        cout << "Third file alredy exist! Data may be lost! continue? Y/N: ";
        char choice;
        while (cin.get(choice) && (tolower(choice) != 'y' && tolower(choice) != 'n'))
        {
            while (cin.get() != '\n')
                continue;
            cout << "Y/N: ";
        }
        if (tolower(choice) == 'y')
            exit(EXIT_FAILURE);
    }
    check.close();

    ofstream fout(argv[3]);
    char ch;
    while (fin1 && fin2)
    {
        while (fin1.get(ch) && ch != '\n')
            fout << ch;
        fout << ' ';
        while (fin2.get(ch) && ch != '\n')
            fout << ch;
        fout << '\n';
    }
    if (fin1)
        while (fin1.get(ch))
            fout << ch;
    else if (fin2)
        while (fin1.get(ch))
            fout << ch;
    return 0;
}