//  Следующее упражнение позволит попрактиковаться в написании функций, работающих с массивами и структурами. Ниже представлен каркас программы.
// Дополните его функциями, описанными в комментариях.
#include <iostream>
#include <cstring>
using namespace std;
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
// getinfо() принимает два аргумента :указатель на первый элемент массива структур student и значение int, представляющее количество элементов в массиве.
// Функция запрашивает и сохраняет данные о студентах. Ввод прекращается либо после наполнения массива, либо при вводе пустой строки в качестве имени студента.
// Функция возвращает действительное количество введенных злементов.
int getinfo(student pa[], int n);
// displayl () принимает в качестве аргумента структуру student и отображает ее содержимое.
void displayl(student st);
// display2 () принимает адрес структуры student в качестве аргумента и отображает ее содержимое.
void display2(const student *ps);
// display3() принимает указатель на первый элемента массива структур student и количество элементов в этом массиве и отображает содержимое всех структур в массиве.
void display3(const student pa[], int n);
int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        displayl(ptr_stu[i]);
        display2(&ptr_stu[i]);
        display3(ptr_stu, entered);
        delete[] ptr_stu;
        cout << " Done\n";
        return 0;
    }
}

// getinfо() принимает два аргумента: указатель на первый элемент массива структур student и значение int, представляющее количество элементов в массиве.
// Функция запрашивает и сохраняет данные о студентах. Ввод прекращается либо после наполнения массива, либо при вводе пустой строки в качестве имени студента.
// Функция возвращает действительное количество введенных злементов.
int getinfo(student pa[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << "\tStudent #" << i + 1 << endl
             << "Name (or just press enter to stop input):\n";
        cin.getline(pa[i].fullname, SLEN);
        if (strcmp(pa[i].fullname, ""))
        {
            i++;
            cout << "Hobby: ";
            cin.getline(pa[i].hobby, SLEN);
            cout << "OOP level: ";
            while (1)
            {
                if (cin >> pa[i].ooplevel)
                {
                    cin.get();
                    break;
                }
                else
                {
                    cout << "Bad input. Enter integer: ";
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                }
            }
        }
    }
    cout << "Input comlete\n";
    return i;
}

// displayl() принимает в качестве аргумента структуру student и отображает ее содержимое.
void displayl(student st)
{
    cout << st.fullname << endl
         << st.hobby << endl
         << "OOP lvl: " << st.ooplevel << endl
         << endl;
}

// display2 () принимает адрес структуры student в качестве аргумента и отображает ее содержимое.
void display2(const student *ps)
{
    cout << ps->fullname << endl
         << ps->hobby << endl
         << "OOP lvl: " << ps->ooplevel << endl
         << endl;
}

// display3() принимает указатель на первый элемента массива структур student и количество элементов в этом массиве и отображает содержимое всех структур в массиве.
void display3(const student pa[], int n)
{
    for (int i = 0; i<n; i++)
    
            cout << pa[i].fullname << endl
         << pa[i].hobby << endl
         << "OOP lvl: " << pa[i].ooplevel << endl
         << endl;    
}