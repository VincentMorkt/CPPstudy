// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    // std::cin.get();
    return 0; 
}
*����~�e��Kz���[bB�L�Z�����=5����ξ~*+vP�t��߹�]kӨ%��r�cm �c�m5���Y��s��e�k,�������ϵͲ7�;q*s����ռva[��f�.�3_��wRP15nj��.���=����_cʋu�զ�c��߂|�����Ƕ*������gf���&�_F��.�eׯ"x-t����!��p[1�.�J��������o�_��
s齠ar�