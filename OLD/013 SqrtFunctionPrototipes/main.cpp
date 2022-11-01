#include <iostream>
#include <cmath>
int main()
{
    using namespace std;
    cout <<"Enter the circle area: ";
    double area=0;
    cin >>area;
    cout <<endl <<"Radius = " <<sqrt(area/M_PI);
    cin.get();
    cin.get();
    return 0;
}