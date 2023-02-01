// 1. Какие разновидности функций являются хорошими кандидатами на то, чтобы быть встроенными?
// Те функции, определение которых может поместиться в одну строку.

// 2. Предположим, что функция song() имеет следующий прототип:
// void song(char *name, int times);

// а. Как модифицировать этот прототип , чтобы для переменной times по умолчанию принималось значение 1?
// void song(char *name, int times = 1);

// б. Какие изменения следует внести в определение функции?
// Никаких изменений в определение вносить не нужно

// в. Можно ли переменной name присвоить используемое по умолчанию значение
// "О, Му Рара "?
// Да, строковой литерал имеет тип char *. При этом либо второй аргумент times должен иметь значение по умолчанию, либо аргумент name должен находиться справа.

// 3. Напишите перегруженные версии функции iquote(), которая отображает аргументы ,заключенные в двойные кавычки. Напишите три версии: одну для аргумента типа int,
// другую для аргумента типа double и третью для аргумента типа string.

#include <iostream>
#include <string>
void iquote(int x)
{
    std::cout << '\"' << x << '\"' << std::endl;
}

void iquote(double x)
{
    std::cout << std::fixed << '\"' << x << '\"' << std::endl;
}

void iquote(std::string str)
{
    std::cout << '\"' + str + '\"';
}

// 4. Пусть имеется следующая структура:
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
// а. Напишите функцию, которая имеет формальный аргумент - ссылку на структуру bох и отображает значение каждого члена структуры.
void BoxShow(box &boxName)
{
    std::cout << boxName.maker << ':' << std::endl
              << "height: " << boxName.height << std::endl
              << "width: " << boxName.width << std::endl
              << "length: " << boxName.length << std::endl
              << "volume: " << boxName.length << std::endl;
}

// б. Напишите функцию, которая имеет формальный аргумент - ссылку на структуру bох и устанавливает член volume в результат произведения членов height, width и length.

void BoxVolume(box &boxName)
{
    boxName.volume = boxName.height * boxName.width * boxName.length;
}

// 5. Какие изменения понадобится внести в листинг 7.15, чтобы функции fill() и show() использовали ссылочные параметры?

// arrobj.cpp -- functions with array objects
#include <iostream>
#include <array>
#include <string>
const int Seasons = 4;
const std::array<std::string, Seasons> Snames =
    {"Spring", "Summer", "Fall", "Winter"};

void fill(std::array<double, Seasons> &pa); // модифицировано здесь и в определении с void fill(std::array<double, Seasons> * pa);
void show(std::array<double, Seasons> da);
int main()
{
    std::array<double, 4> expenses;
    fill(expenses);
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons> &pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa[i]; // модифицировано с std::cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total: $" << total << '\n';
}

// 6. Ниже дано описание результатов, которые требуется обеспечить. Укажите, может ли каждый из них быть получен с помощью аргументов по умолчанию, путем перегрузки функций,
// тем и другим способом, или же можно обойтись без этих средств. Предоставьте необходимые прототипы.

// а. Функция mass(density, volume) возвращает массу тела, имеющего плотность density и объем volume,
// а функция mass(density) возвращает массу тела, имеющего плотность density и объем 1.0 кубический метр. Все величины имеют тип double.
// результат может быть получен с помощью аргументов по умолчанию, перегрузка функций не требуется
double mass(double density, double volume = 1);

// б. Вызов repeat(10, "I 'm ОК") отображает указанную строку 10 раз, а вызов repeat("But you're kind of stupid") отображает заданную строку 5 раз.
// результат может быть получен с помощью перегрузки функций, для использования аргументов по умолчанию требуется, чтобы соответствуюющие аргументы находились справа.
void repeat(int n, const char* ch);
void repear(const char * ch);

// в. Вызов average(3, 6) возвращает среднее значение типа int двух аргументов int, а вызов average (3.О, 6.О) - среднее значение типа double двух значений double.
// результат может быть получен с помощью шаблонной функции.
template <typename T>
T average(T x, T y);

// г. Вызов mangle("I'm glad to meet you") возвращает символ I или указатель на строку "I'm glad to meet you" в зависимости от того,
// присваивается возвращаемое значение переменной типа char или переменной типа char*.

// Не нашёл ответ

// 7. Напишите шаблон функции, которая возвращает больший из двух ее аргументов.

template <typename AnyType>
AnyType larger(AnyType a, AnyType b) { return a > b ? a : b; }

// 8. Используя шаблон из вопроса 7 и структуру bох из вопроса 4, предоставьте специализацию шаблона, которая принимает два аргумента типа bох и возвращает
// тот из них, у которого больше значение volume.

template <>
box larger<box>(box a, box b)
{
    return a.volume > b.volume ? a : b;
}

// 9. Какие типы назначены переменным vl, v2 , v3, v4 и v5 в следующем коде (предполагается, что код является частью завершенной программы)?
// int g (int х); 
// float m = 5.5f;
// float &rm = m;
// decltype (m) vl = m;     тип float
// decltype (rm) v2 = m;    тип float &
// decltype ((m)) vЗ = m ;  тип float &
// decltype (g(100)) v4 ;   тип int (возвращаемый тип функции)
// decltype (2.0 * m) v5 ;  тип double