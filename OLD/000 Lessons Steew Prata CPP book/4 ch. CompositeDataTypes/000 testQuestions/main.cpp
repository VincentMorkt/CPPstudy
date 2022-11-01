#include <iostream>
#include <array>
#include <vector>
#include <cstring>

//8
struct fish 
{
    char kind[20];
    int weightOunces;
    float lenghtInches;   
};

int main ()
{
    //1
    using namespace std;
    float chuck [13]; 
    long double dipsea [64];
    //2
    array <char,30> actor;
    array <short,100> betsie;
    //3
    int intMassive [5] = {1,3,5,7,9};
    //4
    int even = intMassive[0]+intMassive[4];
    //5
    float ideas [2] = {1,23.4};
    cout << "ideas [1] = " << ideas[1] << endl;    
    //6
    char charMassive[13] = "cheesburger";
    //7
    string menu = "Waldorg Salad";
    //cout << menu << endl;
    //9
    fish yaz = {"yaz",77,13.77};
    //10
    enum Response {No,Yes,Maybe};
    //11
    double ted = 36.6;
    double *td = &ted;
    cout << "ted = *td = " << *td <<endl;
    //12
    float treacle [10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "treacle[0] = *treacle = "<< *treacle << endl
    << "treacle[9] = *(treacle+9) = " << *(treacle+9) <<endl;
    //13
    int num = 3;
    //cin >> num;
    int *intM13 = new int[num];
    delete[] intM13;
    vector<int>intM13_2(num);
    //14
    cout << (int*) "Home of the jolly bytes" <<endl; // вывод на экран адреса первого символа строки
    //15
    fish *pf=new fish;
    cin>>pf->kind;
    //16
    //cin.getline(address,80); позволяет ввести до 80 символов с пробелами и записать их в массив address. 
    //cin >> позволяет ввести любое количество символов без пробелов. Риск выйти за пределы массива при записи. 
    //Пробел будет читаться как нулевой символ, а все введённые после данные остануться в очереди потока istream.
    
    //17
    const int num1=10;
    std::vector<std::string>vs(num1);
    std::array<std::string,num1>as;
    








}