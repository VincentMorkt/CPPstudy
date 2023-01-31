/*Структура CandyBar включает три члена, как описано в предыдущем упражнении. Напишите программу, которая создает массив из трех структур CandyBar,
инициализирует их значениями по вашему усмотрению и затем отображает содержимое каждой структуры.*/

#include <iostream>     
#include <string>       // заголовочный файл для работы с объектами класса string - строками, и связанными с ними функциями
using namespace std;    // подключение пространства std. сделано в общем пространстве программы для доступа к пространству имён всех блоков
                        // более качественной и менее ленивой альтернативой является использование нотации std::... 
                        //или подключение пространства имён (или отдельных имён из него) в каждом {блоке программы}
struct CandyBar     // объявление структуры в общем пространстве программы (структура может быть объявленна и внутри функции main)
{
    string titel;   // члены структуры. в качестве первого члена использован объект string
    double weight;  
    long calories;
};
int main ()
{
    CandyBar snack[3] // объявление массива структур
    {
        {"Mocha Munch",2.3,350},                    // инициализация массива структур
        {"Snickers",1.7,249},
        {"Arrakis gummy worm",7199980.02,642000000}
    };
    cout << "\tTitel 1:" <<snack[0].titel <<endl    // вывод на экран значений данных структур
    <<"\t\tWeight:\t" <<snack[0].weight <<endl
    <<"\t\tCalories: " <<snack[0].calories <<endl<<endl;  
    cout << "\tTitel 2:" <<snack[1].titel <<endl 
    <<"\t\tWeight:\t" <<snack[1].weight <<endl
    <<"\t\tCalories: " <<snack[1].calories <<endl<<endl;   
    cout << "\tTitel 3:" <<snack[2].titel <<endl 
    <<"\t\tWeight:\t" <<int(snack[2].weight) <<endl
    <<"\t\tCalories: " <<snack[2].calories <<endl<<endl;            
    cin.get();
    return 0; 
}