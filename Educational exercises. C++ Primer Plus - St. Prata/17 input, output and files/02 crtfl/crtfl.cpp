// 2. Напишите программу, которая копирует клавиатурный ввод
// (вплоть до эмулируемого конца файла) в файл,
// имя которого передано в командной строке

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;

    if (argc > 2)
    {
        cerr << "Incorect numbers of file names. You can create only one file!";
        exit(EXIT_FAILURE);
    }
    ifstream check(argv[1]);
    if (check.is_open())
    {
        cerr << "File alredy exist!";
        exit(EXIT_FAILURE);
    }
    ofstream fout(argv[1]);
    char ch;
    while (cin.get(ch))
        fout << ch;
    return 0;
}