#include <iostream>
#include "cow.h"

int main()
{
    {
        using namespace std;
        Cow cow1;
        Cow cow2("Barbara", "dance", 123);
        Cow cow3(cow2);
        cow1 = cow3;
        cow1.ShowCow(); 
    }
    std::cin.get();
    return 0;
}