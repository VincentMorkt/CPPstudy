// 6. Рассмотрите определение класса, предложенное в упражнении 5 главы 14. Если вы еще не делали это упражнение, выполните его сейчас. Затем сделайте следующее.
// Напишите программу, которая использует стандартный ввод-вывод С++ и файловый ввод-вывод в сочетании с данными типов employee, manager, fink и highfink, как определено в упражнении 5 из главы 14.
// Программа должна быть аналогична главным строкам листинга 17.17 в том, что должна позволять вносить новые данные в файл.
// При первом запуске программа должна запросить данные у пользователя, показать все введенные записи и сохранить информацию в файл.
// При последующих запусках она должна сначала прочитать и отобразить данные файла, дать возможность пользователю добавить новые данные и отобразить все данные снова.
// Единственное отличие должно состоять в том, что данные должны быть представлены в виде массива указателей на тип employee.
// Таким образом, указатель может указывать на объект employee либо на объект любого из трех производных от него типов.
// Сохраняйте массив маленьким, чтобы облегчить его проверку программой; например, его размер можно ограничить 10 элементами:
// const int МАХ = 10; // не более 10 объектов
// employee *ре[МАХ];
// Для клавиатурного ввода программа должна использовать меню, чтобы предоставить пользователю выбор типа создаваемого объекта.
// С меню должен быть связан оператор switch, позволяющий использовать операцию new для создания объекта требуемого типа и присваивать адрес этого объекта
// указателю в массиве ре. Затем этот объект может вызвать виртуальную функцию setall() для запроса соответствующих данных от пользователя:
// pc[i]->setall(); // вызывает функцию, соответствующую типу объекта
// Чтобы обеспечить сохранение данных в файле, необходимо объявить виртуальную функцию writeall():
// for (i = 0; i < index; i++)
// pc[i]->writeall(fout); // объект fout типа ofstream подключен к выходному файлу
// Сложность представляет восстановление данных из файла. Проблема состоит в том, как программа узнает, какого типа объект будет восстановлен следующим:
// employee, manager, fink либо highfink? Один из возможных подходов к решению этой проблемы заключается в следующем:
// при записи данных объекта в файл предварить его целым числом, идентифицирующим тип следующего объекта.
// Затем при вводе из файла программа может читать это целое число и применять switch для создания объекта соответствующего типа для приема данных:

// enum classkind
// {
//     Employee,
//     Manager,
//     Fink,
//     Highfink
// }; // в заголовке класса
// // ...
// int classtype;
// while ((fin >> classtype).get(ch))
// { // символ новой строки отделяет целое число от данных
//     switch (classtype)
//     {
//     case Employee:
//         pc[i] = new employee;
//         break;

//         // Затем можно использовать указатель, чтобы вызвать виртуальную функцию getall() для считывания информации:
//         pc[i++]->getall();

// ре 14-5.срр
// useempl.cpp --использование классов abstr_emp
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "emp.h"
const int MAX = 10; // не более 10 объектов

// создаёт новый динамический объект в соответствии с прочитанным типом, читает в него данные из файла и возвращает его адрес
abstr_emp *new_obj(std::ifstream &fin, classkind choice);

// ищет файл "emp_list.dat" и читает его, создаёт динамические объекты,
// передаёт их адреса в массив указателей до заполнения массива или до окончания файла.
// если файл не найден или не было прочитанно ни одного объекта, возвращает false
int read_emp_file(std::ifstream &fin, abstr_emp *[], int size);
void eatline()
{
    cin.clear();
    while (cin.get() != '\n')
        continue;
}

int main()
{

    abstr_emp *pe[MAX]; // массив указателей на объекты

    // поиск файла
    ifstream fin("emp_list.dat"); // объект файлового ввода, пытается связаться с дата-файлом

    // если файл найден и из него прочитанн хотя-бы один объект
    int sizefile;                               // счётчик прочитанных объектов
    if (sizefile = read_emp_file(fin, pe, MAX)) // если файл был найден и количество прочитанных объектов не 0;
    {
        cout << " --employees list, reading from file--\n\n";
        for (int i = 0; i < sizefile; i++) // отображение всех прочитанных объектов (если они есть)
        {
            pe[i]->ShowAll();
            cout << endl;
        }
    }
    fin.close();

    // ввод новых объектов
    char choice;
    int sizefact = sizefile;
    while (sizefact < MAX)
    {
        cout << " --Adding new employees--\n"
             << "e: employee      m: manager\n"
             << "f: fink          h: highfink\n"
             << "enter yore choice <q: quit>: ";
        cin.get(choice);
        eatline();
        if (tolower(choice) == 'q' || choice == '5')
            break;
        switch (tolower(choice))
        {
        case 'e':
        case '1':
        {
            employee *temp = new employee;
            temp->SetAll();
            pe[sizefact] = temp;
            sizefact++;
            break;
        }
        case 'm':
        case '2':
        {
            manager *temp = new manager;
            temp->SetAll();
            pe[sizefact] = temp;
            sizefact++;
            break;
        }
        case 'f':
        case '3':
        {
            fink *temp = new fink;
            temp->SetAll();
            pe[sizefact] = temp;
            sizefact++;
            break;
        }
        case 'h':
        case '4':
        {
            highfink *temp = new highfink;
            temp->SetAll();
            pe[sizefact] = temp;
            sizefact++;
            break;
        }
        default:
            cout << "E--incorrect input\n";
            break;
        }
    }

    if (sizefile >= MAX)
        cout << "M--input stoped, array size liit\n";
    else
        cout << "M--you break input\n";

    ofstream fout("emp_list.dat", ios_base::out | ios_base::app);
    for (int i = sizefile; i < sizefact; i++)
        pe[i]->WriteToFile(fout);

    cout << " --employees list--\n\n";
    for (int i = 0; i < sizefact; i++) // отображение всех прочитанных объектов
    {
        pe[i]->ShowAll();
        cout << endl;
    }

    // ending
    for (int i = 0; i < sizefact; i++)
        delete pe[i];
    cin.get();
    return 0;
}

// ищет файл "emp_list.dat" и читает его, создаёт динамические объекты,
// передаёт их адреса в массив указателей до заполнения массива или до окончания файла.
// если файл не найден или не было прочитанно ни одного объекта, возвращает false
int read_emp_file(std::ifstream &fin, abstr_emp *pe[], int size)
{
    using namespace std;
    const int MAX = size; // локальный объект, чтобы не переписывать код

    if (fin.is_open()) // если дата-файл существует
    {
        string emp_type; // временная переменная для чтения типа объекта
        int i = 0;       // счётчик объектов и индекс для доступа к массиву pe

        // чтение файла и создание массива указателей на объекты
        while (fin) // пока не достигнут конец файла или не произошёл какой-либо сбой чтения
        {
            getline(fin, emp_type);
            if (emp_type == "")
                continue;                              // если прочитана пустая строка, переходим к чтению следующей строки
            pe[i] = new_obj(fin, getChoice(emp_type)); // присваивает элементу массива адресс, возвращённый фунецией new_obj
            i++;                                       // инкремент счётчика
            if (i >= MAX)                              // если достигнут предел размера массива
            {
                cout << "M--array size limit\n";
                return i;
            }
        }
        if (i == 0)
            cout << "M--data file empy or damadget\n";
        return i;
    }
    else
        cout << "M--data file not found\n";
    return 0;
}

// создаёт новый динамический объект в соответствии с прочитанным типом, читает в него данные из файла и возвращает его адрес
abstr_emp *new_obj(std::ifstream &fin, classkind choice)
{
    switch (choice)
    {
    case Employee:
    {
        employee *emp_obj = new employee;
        emp_obj->ReadFromFile(fin);
        return emp_obj;
    }
    case Manager:
    {
        manager *emp_obj = new manager;
        emp_obj->ReadFromFile(fin);
        return emp_obj;
    }
    case Fink:
    {
        fink *emp_obj = new fink;
        emp_obj->ReadFromFile(fin);
        return emp_obj;
    }
    case Highfink:
    {
        highfink *emp_obj = new highfink;
        emp_obj->ReadFromFile(fin);
        return emp_obj;
    }
    default:
        cerr << "E--error in new_obj/switch. incorrect classkind\n";
        return nullptr;
    }
}