// Вернитесь к программе из листинга 7.7 и замените три функции обработки массивов версиями, которые работают с диапазонами значений, заданными парой указателей.
// Функция fill _ array () вместо возврата действительного количества прочитанных значений должна возвращать указатель на место, следующее за последним введенным элементом;
// прочие функции должны использовать его в качестве второго аргумента для идентификации конца диапазона данных.

// arrfun3.cpp-- функция работы с массивами и применение const
#include <iostream>
const int Max = 5;
// Прототипы функций
double * fill_array(double *start, double *end);
void show_array(const double *start, double *end);
void revalue(double r, double *start, double *end);

int main()
{
    using namespace std;
    double properties[Max];
    double *size = fill_array(properties, properties+Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    cin.get();
    cin.get();
    return 0;
}

double * fill_array(double *start, double *end) // ОСТАНОВИЛСЯ ТУТ
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < end - start; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        // ввод значения
        cin >> temp;
        if (!cin) // неправильный ввод
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n"; // процесс ввода прекращен
            break;
        }
        else if (temp < 0)
            break;
        *(start+i) = temp;
    }
    return (start+i);  
}

void show_array(const double *start, double *end) 
{
    using namespace std;
    for (int i = 0; i < end - start; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << *(start+i) << endl;
    }
} 

void revalue(double r, double *start, double *end)
{
    for (int i = 0; i < end - start; i++)
        *(start+i) *= r;
}