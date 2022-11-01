#include <iostream>
void vincent(int);

int main()
{
    using namespace std;
    cout <<"Pick an integer: ";
    int nudes=0;
    cin >>nudes;
    vincent (nudes);
    cin.get();
    cin.get();
    return 0;
}
void vincent(int n)
{
    using namespace std;
    cout <<"Vincent says send nudes "<<n <<" times."<<endl;
}