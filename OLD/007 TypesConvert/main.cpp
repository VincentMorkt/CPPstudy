#include <stdio.h>

int main ()
{
    int var = 'A'; // неявное преобразование char-->int (безопасное)
    printf("char 'A' --> int: %d\n",var); 

    char varChar = 66; // неявное преобразование int-->char (небезопасное)
    printf("int 66 --> char: %c\n",varChar);
    printf("int 66 --> char // interpitated char like int (%%d): %d\n",varChar); // вывод char = 66 через спецификатор %d, предназначеный для вывода десятичных чисел
    

    return 0;
}