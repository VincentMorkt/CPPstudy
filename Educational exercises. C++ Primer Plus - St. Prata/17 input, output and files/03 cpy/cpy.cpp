// 3. Напишите программу, копирующую один файл в другой. 
// Имена файлов программа должна получать из командной строки. 
// Если не удается открыть файл, должно выдаваться соответствующее сообщение. 

#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[])
{
    using namespace std;

    if (argc != 3)
    {
        cerr << "Incorect numbers of file names. Enter two file names: " << argv[0] << " name_from name_to";
        exit(EXIT_FAILURE);
    }

    ifstream fin(argv[1]);
    if (!fin.is_open())
    {
        cerr << "First file dosent exist!";
        exit(EXIT_FAILURE);
    }

    ifstream check(argv[2]);
    if (check.is_open())
    {
        cout << "Second file alredy exist! Data may be lost! continue? Y/N: ";
        char choice;
        //while (cin.get() != '\n');
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

    ofstream fout(argv[2]);
    char ch;
    while (fin.get(ch))
        fout << ch;
    return 0;
}