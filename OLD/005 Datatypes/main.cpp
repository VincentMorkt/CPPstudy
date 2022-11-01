#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    size_t sizeOfVariable = sizeof(bool);
    printf("%s min: false\t\t\t%s max: true\t\t\tSize of %s = %lu\n","bool","bool","bool",sizeOfVariable);  
    
    sizeOfVariable = sizeof(char);
    printf("%s min: %d\t\t\t%s max: %d\t\t\tSize of %s = %lu\n","char",CHAR_MIN,"char",CHAR_MAX,"char",sizeOfVariable);

    sizeOfVariable = sizeof(unsigned char);
    printf("%s min: %d\t\t%s max: %d\t\tSize of %s = %lu\n","unsigned char",0,"unsigned char",UCHAR_MAX,"unsigned char",sizeOfVariable);

    sizeOfVariable = sizeof(char16_t);
    printf("%s min: %d\t\t\t%s max: %d\t\t\tSize of %s = %lu\n","char16_t",000,"char16_t",000,"char16_t",sizeOfVariable);
    
    sizeOfVariable = sizeof(char32_t);
    printf("%s min: %d\t\t\t%s max: %d\t\t\tSize of %s = %lu\n","char32_t",000,"char32_t",000,"char32_t",sizeOfVariable);

    sizeOfVariable = sizeof(short);
    printf("%s min: %d\t\t%s max: %d\t\tSize of %s = %lu\n","short",SHRT_MIN,"short",SHRT_MAX,"short",sizeOfVariable);  

    sizeOfVariable = sizeof(unsigned short);
    printf("%s min: %d\t\t%s max: %d\tSize of %s = %lu\n","unsigned short",0,"unsigned short",USHRT_MAX,"unsigned short",sizeOfVariable);    

    sizeOfVariable = sizeof(int);
    printf("%s min: %d\t\t%s max: %d\t\tSize of %s = %lu\n","int",INT_MIN,"int",INT_MAX,"int",sizeOfVariable); 

    sizeOfVariable = sizeof(unsigned int);
    printf("%s min: %d\t\t%s max: %lu\tSize of %s = %lu\n","unsigned int",0,"unsigned int",UINT_MAX,"unsigned int",sizeOfVariable); 

    sizeOfVariable = sizeof(long);
    printf("%s min: %ld\t\t%s max: %ld\t\tSize of %s = %lu\n","long",LONG_MIN,"long",LONG_MAX,"long",sizeOfVariable);      

    sizeOfVariable = sizeof(unsigned long);
    printf("%s min: %d\t\t%s max: %lu\tSize of %s = %lu\n","unsigned long",0,"unsigned long",ULONG_MAX,"unsigned long",sizeOfVariable);      

    sizeOfVariable = sizeof(long long);
    printf("%s min: %lld\t%s max: %lld\t\tSize of %s = %lu\n","long long",LONG_LONG_MIN,"long long",LONG_LONG_MAX,"long long",sizeOfVariable);     

    sizeOfVariable = sizeof(unsigned long long);
    printf("%s min: %d\t\t%s max: %llu\tSize of %s = %lu\n","unsigned long long",0,"unsigned long long",ULONG_LONG_MAX,"unsigned long long",sizeOfVariable);     

    sizeOfVariable = sizeof(float);
    printf("%s min: %f\t\t%s max: %f\tSize of %s = %lu\n","float",__FLT_MIN__,"float",__FLT_MAX__,"float",sizeOfVariable); 

    //one line comment
    sizeOfVariable = sizeof(double);
    printf("%s min: %f\t\t%s max: %f\tSize of %s = %lu\n","double",__DBL_MIN__,"double",__DBL_MAX__,"double",sizeOfVariable); 

    /*multiline comment*/ 
    sizeOfVariable = sizeof(long double);
    printf("%s min: %g\t\t%s max: %g\tSize of %s = %lu\n","long double",__LDBL_MIN__,"long double",__LDBL_MAX__,"long double",sizeOfVariable); 
    
    return 0;
}