// 1. Напишите программу, которая подсчитывает количество символов вплоть до
// первого символа $ в строке, оставляя $ во входном потоке.

#include <iostream>
#include <cctype>

int main()
{
    using namespace std;
    cout << "Enter string, ending with $:\n";
    char ch;
    int countAll = 0;
    int countChar = 0;
    // while (cin.peek() != '$')
    // {
    //     cin.get(ch);
    //     countAll++;
    //     if (!isspace(ch))
    //         countChar++;
    // }

    while (cin.get(ch) && ch != '$')
    {
        countAll++;
        if (!isspace(ch))
            countChar++;
    }
    cin.putback(ch);
    // второй вариант

    cout << "All symbols: " << countAll << endl
         << "Without spaces: " << countChar << endl
         << "next character in the stream: " << (char)cin.get() << endl;
    cin.get();
    cin.get();
}