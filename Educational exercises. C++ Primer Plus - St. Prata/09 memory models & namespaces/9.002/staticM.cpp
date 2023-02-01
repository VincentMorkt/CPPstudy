// Модифицируйте код в листинге 9.9, заменив символьный массив объектом string. Программа больше не должна проверять,
// умещается ли вводимая строка, и для проверки ввода пустой строки может сравнивать вводимую строку со значением " " .

// static.cpp -- using a static local variable
#include <iostream>
#include <string>
// constants
const int ArSize = 10;

// function prototype
void strcount(std::string str);

int main()
{
    using namespace std;
    string input;

    cout << "Enter a line:\n";
    getline(cin, input);
    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
    cin.get();
    // code to keep window open for MSVC++
    /*
    cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}

void strcount(std::string str)
{
    using namespace std;
    static int total = 0; // static local variable
    int count = 0;        // automatic local variable

    cout << "\"" << str << "\" contains ";
    // go to end of string
    count = str.length();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
