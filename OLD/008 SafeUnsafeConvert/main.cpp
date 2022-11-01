#include <stdio.h>

int main ()
{
    printf ("%c\nSafe convertions chain: bool-->char-->int-->double\n%c\n",0,0);

    bool boolDir = true;
    char charDir = boolDir; 
    int intDir = charDir;
    double doubleDir = intDir;

    printf ("\tbool %d (true) --> char '%c' --> int %d --> double %f\n%c\nAnd now we will return to bool with the same data:\n%c\n",boolDir,charDir,intDir,doubleDir,0,0);

    intDir = doubleDir;
    charDir = intDir;
    boolDir = charDir;

    printf ("\tdouble %f --> int %d --> char '%c' --> bool %d\n\tWe don't loose data.\n%c\n",doubleDir,intDir,charDir,boolDir,0);

    printf ("Unsafe convertions chains: double-->int, int-->char, char-->bool\n%c\n",0);

    doubleDir = 9876543210.987654321;
    intDir = doubleDir;
    double doubleRev = intDir;
    printf ("\tdouble %f --> int %d --> double %f \n\tWe loose data!\n%c\n",doubleDir,intDir,doubleRev,0);

    intDir = 54321;
    charDir = intDir;
    int intRev = charDir;
    printf ("\tint %d --> char '%c' --> int %d\n\tWe loose data!\n%c\n",intDir,charDir,intRev,0);

    charDir = 'G';
    boolDir = charDir;
    bool charRev = boolDir;
    printf ("\tchar '%c' --> bool %d --> char '%c'\n\tWe loose data!\n%c\n",charDir,boolDir,charRev,0);

    return 0;
}