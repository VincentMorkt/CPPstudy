#include <iostream>
int main ()
{
    using namespace std;
    cout << "Enter factorial value: ";
    int factorialVal = 0;
    cin >> factorialVal;
    long long factorials [factorialVal];
    factorials[1] = factorials[0] = 1LL;
    for (int i=2;i<factorialVal;i++)
        factorials[i] = i * factorials[i-1];
    for (int i=0;i<factorialVal;i++)
        cout << i <<"! = " << factorials[i]<<endl;
    cin.get();
    cin.get();
    return 0;
}