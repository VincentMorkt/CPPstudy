// Многие лотереи в CШA организованы подобно той, что была смоделирована в листинге 7.4. Во всех их вариациях вы должны выбрать несколько чисел из одного набора,
// называемого полем номеров. (Например, вы можете выбрать 5 чисел из поля 1-47. ) Вы также указываете один номер (называемый меганомером) из второго диапазона,
// такого как 1-27. Чтобы выиграть главный приз, вы должны правильно угадать все номера. Шанс выиграть вычисляется как вероятность угадывания всех номеров в поле,
// умноженная на вероятность угадывания меганомера. Например, вероятность выигрыша в описанном здесь примере вычисляется как вероятность угадывания 5 номеров из 47,
// умноженная на вероятность угадывания одного номера из 27. Модифицируйте листинг 7.4 для вычисления вероятности выигрыша в такой лотерее.

#include <iostream>
long double probability(unsigned numbers, unsigned picks, unsigned mega);
int main()
{
    using namespace std;
    double total, choices, meganumbers;
    // Ввод общего количества номеров и количества номеров, которые нужно угадать
    cout << "Enter the total number of choices on the game card,\n"
            "the number of picks allowed,\n"
            "and the total MEGANUMBERS\n";
    while ((cin >> total >> choices >> meganumbers) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices, meganumbers);
        cout << " of winning.\n";
        cout << "Next three numbers (q to quit): \n";
        // вычисление и вывод шансов
        // Ввод следующих двух чисел (q для завершения)
    }
    std::cout << "\nPress <ENTER> to close."; // закрытие программы
    std::cin.get();                           // ожидание ввода для просмотра результатов работы программы
    return 0;
}
// Следующая функция вычисляет вероятность правильного
// угадывания picks чисел из numbers возможных
long double probability(unsigned numbers, unsigned picks, unsigned mega)
{
    long double result = 1.0; // несколько локальных переменных
    long double n;
    long double m = mega;
    unsigned p;
    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p;
    result *= m;
    return result;
}