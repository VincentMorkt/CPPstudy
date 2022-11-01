#include <iostream>
#include <fstream>
#include <cctype>
int main()
{
    using namespace std;
    ifstream inFile;
    ofstream outFile;
    inFile.open("text.txt");
    outFile.open("result.txt");
    char ch;
    while (inFile.get(ch))
        if (ch == '(')
        {
            inFile.get(ch);
            if (ch == ')')
            {
                outFile << "0\n";
                continue;
            }
            if (!(isblank(ch)||ispunct(ch)||isdigit(ch)||iscntrl(ch)))
                continue;
            while (ch != ')')
            {
                outFile << ch;
                inFile.get(ch);
            }
            outFile << endl;
        }
}