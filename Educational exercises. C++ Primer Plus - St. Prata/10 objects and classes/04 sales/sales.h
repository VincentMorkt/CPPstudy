// 4. Выполните упражнение 4 из главы 9, но преобразуйте структуру Sales и ассоциированные с ней функции в класс и методы.
// Замените функцию setSales(Sales &, double[], int) конструктором. Реализуйте интерактивный метод setSales(Sales &), используя конструктор.
// Оставьте класс в пространстве имен SALES.

// 4. Напишите программу, включающую три файла и использующую следующее пространство имен

// Первый файл должен быть заголовочным и содержать пространство имен.
// Второй файл должен содержать исходный код и расширять пространство имен,
// предоставляя определения трех прототипированных функций.
// В третьем файле должны объявляться два объекта Sales.
// Он должен использовать интерактивную версию функции setSales() для предоставления значений первой структуре
// и неинтерактивную версию той же функции для предоставления значений второй структуре.
// Он также должен отображать содержимое обеих структур с помощью функции showSales ().

// sales.h -- объявление класса и пространства имён

#ifndef SALES_H_
#define SALES_H_

namespace SALES // объявление пространства имён
{
    const int QUARTERS = 4; // количество кварталов

    class Sales // объявление класса
    {
    private:
        double sales[QUARTERS]; // массив данных по кварталам
        double average;         // переменные для хранение среднего, максимального и минимального значений
        double max;
        double min;

    public:
        Sales (); // конструктор по умолчанию
        
        // Копирует значения из массива в аргументе в массив данных класса, вычисляет и сохраняет среднее арифметическое, максимальное и минимальное значения введенных чисел;
        // оставшиеся элементы sales, если таковые есть, устанавливаются в 0
        void setSales(const double ar[]);

        // Интерактивно подсчитывает продажи за 4 квартала, сохраняет их в члене  sales,
        // вычисляет и сохраняет среднее арифметическое, а также максимальное и минимальное значения введенных чисел
        void setSales();

        // Отображает всю информацию из структуры s
        void showSales() const;
    };
}

#endif
