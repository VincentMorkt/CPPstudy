// Ниже представлена общая структура программы:
#include <iostream>
using namespace std;
#include <cstring> // для strlen(), strcpy()
struct stringy
{
    char *str; // указывает на строку
    int ct;    // длина строки (не считая символа'\0')
};
// Здесь размещаются прототипы функций set() и show()
template <typename T>
void show(T name, int num = 1);
void show(const stringy &st, int num = 1);
void set(stringy &st, char *ch);

//
int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be. ";
    set(beany, testing); // первым аргументом является ссылка,
    // Выделяет пространство для хранения копии testing,
    // использует элемент типа str структуры beany как указатель
    // на новый блок, копирует testing в новый блок и
    // создает элемент ct структуры beany
    show(beany);    // выводит строковый член структуры один раз
    show(beany, 2); // выводит строковый член структуры два раза
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);    // выводит сроку testing один раз
    show(testing, 3); // выводит строку testing три раза
    show("Done!");
    cin.get();
    return 0;
}
template <typename T>
void show(T name, int num)
{
    for (int i = 0; i < num; i++)
        cout << name << endl;
}
void show(const stringy &st, int num)
{
    for (int i = 0; i < num; i++)
        cout << st.str << endl;
}
void set(stringy &st, char *ch)
{
    st.ct = strlen(ch);
    st.str = ch;
}

// Завершите программу, создав соответствующие функции и прототипы.Обратите внимание, что в программе должны быть две функции show(),
// и каждая из них использует аргументы по умолчанию. Где необходимо, используйте const.
// Функция set() должна использовать операцию new для выделения достаточного пространства памяти под хранение заданной строки.
// Используемые здесь методы аналогичны методам, применяемым при проектировании и реализации классов.
// (В зависимости от используемого компилятора, может понадобиться изменить имена заголовочных файлов и удалить директиву using.)