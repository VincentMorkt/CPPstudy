/* Выполните упражнение 6 , но вместо объявления массива из трех структур CandyBar используйте операцию new для динамического размещения массива.

Структура CandyBar включает три члена, как описано в предыдущем упражнении. Напишите программу, которая создает массив из трех структур CandyBar,
инициализирует их значениями по вашему усмотрению и затем отображает содержимое каждой структуры.*/

#include <iostream>     
#include <string>   // заголовочный файл для работы с объектами класса string - строками, и связанными с ними функциями

struct CandyBar     // объявление структуры в общем пространстве программы (структура может быть объявленна и внутри функции main)
{
    std::string titel;   // члены структуры. в качестве первого члена использован объект string
    double weight;  
    long calories;
};
int main ()
{
    using namespace std;                // подключение пространства std 
    CandyBar*snack = new CandyBar[3];   // объявление указателя на динамический массив структур
    
    snack[0] = {"Mocha Munch",2.3,350}; // инициализация массива структур
    snack[1] = {"Snickers",1.7,249};
    snack[2] = {"Arrakis gummy worm",7199980.02,642000000};
    
    cout << "\tTitel 1:" <<snack[0].titel <<endl    // вывод на экран текстовых литералов и значений членов элементов массива структур
    <<"\t\tWeight:\t" <<snack[0].weight <<endl
    <<"\t\tCalories: " <<snack[0].calories <<endl<<endl;  
    cout << "\tTitel 2:" <<snack[1].titel <<endl 
    <<"\t\tWeight:\t" <<snack[1].weight <<endl
    <<"\t\tCalories: " <<snack[1].calories <<endl<<endl;   
    cout << "\tTitel 3:" <<snack[2].titel <<endl 
    <<"\t\tWeight:\t" <<int(snack[2].weight) <<endl // приведение к int 
    <<"\t\tCalories: " <<snack[2].calories <<endl<<endl;            
    delete [] snack;    // освобождение памяти
    cin.get();
    return 0; 
}