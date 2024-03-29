// // 1 . Какой схемой хранения вы воспользуетесь в следующих ситуациях?
// // а. homer - это формальный аргумент (параметр) функции.
// // автоматическая переменная
// // б. Переменная secret должна совместно использоваться в двух файлах.
// // статическая переменная с внешним связыванием
// // в. Переменная topsecret должна быть доступна функциям одного файла, но скрыта от других файлов.
// // статическая переменная с внутренним связыванием
// // г. Переменная beencalled фиксирует количество вызовов функции, которая ее содержит.
// // статическая переменная без связывания (объявленная внутри функции с использованием ключевого слова static)

// // 2. Опишите различия между объявлением using и директивой using.
// // Объявление имеет вид using nameOfNamespace::name (using std::cout;) и добавляет отдельное имя в декларативную область. Объявление using будет равноценно
// // объявлению объекта с соответсвующим именем. Мы не сможем объявить ещё один объект с таким же именем, и объявленное в блоке имя скроет глобальное.
// // Дирректива имеет вид using namespace nameOfNamespcae (using namespace std;) и добавляет все имена из пространства имён в декларативную область.
// // Применение диррективы using будет похоже на добавление имён в глобальную область видимости. Мы сможем объявить ещё один объект с таким же именем и он скроет имя,
// // входящее в пространство имён.

// // 3. Перепишите следующий код таким образом, чтобы в нем не использовалось ни объявление, ни директива using.
// // просто воскользуемся операцией разрешения контекста ::
// #include <iostream>
// int main()
// {
//     double x;
//     std::cout << "Enter value : ";
//     while (!(std::cin >> x))
//     {
//         std::cout << "Bad input.Please enter a number : "; // неверный ввод
//         std::cin.clear();
//         while (std::cin.get() != '\n')
//             continue;
//     }
//     std::cout << "Value = " << x << std::endl;
//     return 0;
// }

// // 4. Перепишите следующий код таким образом, чтобы в нем использовались объявления using вместо директивы using.
// #include <iostream>
// int main()
// {
//     using std::cin;
//     using std::cout;
//     using std::endl;
//     double x;
//     cout << "Enter value : ";
//     while (!(cin >> x))
//     {
//         cout << "Bad input.Please enter a number : "; // неверный ввод
//         cin.clear();
//         while (cin.get() != '\n')
//             continue;
//     }
//     cout << "Value = " << x << endl;
//     return 0;
// }

// // 5. Предположим, что функция average (3,6) должна возвращать значение int, которое является средним арифметическим двух аргументов типа int,
// // когда она вызывается в одном файле, и значение double, которое является средним арифметическим от двух аргументов типа int,
// // когда вызывается в другом файле одной и той же программы. Как это можно реализовать?
// // необходимо сделать функции с внутренним связыванием в каждом из файлом, с использованием ключевого слова static перед прототипом и определением функции:
// static double average(int x, int y);
// static double average(int x, int y)
// {
//     return (double(x + y) / 2);
// }
// // и также для второго файла, но без приведения типа

// // 6. Какие данные будет выводить следующая программа, состоящая из двух файлов?
// // filel.срр
// #include <iostream>
// using namespace std;
// void other();
// void another();
// int x = 10;
// int y;
// int main()
// {
//     cout << x << endl; // будет отображено значение глобальной переменной x: 10
//     {
//         int x = 4;
//         cout << x << endl; // значение локальной переменной x: 4
//         cout << y << endl; // значение неинициализированной глобальной переменной y: (мусор)
//     }
//     other();
//     another();
//     return 0;
// }
// void other()
// {
//     int y = 1;                                    // значение локальной переменной y: 1
//     cout << " Other: " << x << ", " << y << endl; // значение глобальной переменной x: 10 и значение локальной переменной y: 1
// }
// // file2.срр
// #include <iostream>
// using namespace std;
// extern int x;
// namespace
// {
//     int y = -4;
// }
// void another()
// {
//     cout << " another(): " << x << ", " << y << endl; // значение глобальной переменной x: 10 и значение переменной неименнованного пространства имён y: -4
// }

// // 7. Что будет выводить следующая программа?
// #include <iostream>
// using namespace std;
// void other();
// namespace n1
// {
//     int x = 1;
// }
// namespace n2
// {
//     int x = 2;
// }
// int main()
// {
//     using namespace n1;
//     cout << x << endl; // n1::x: 1
//     {
//         int x = 4;                                           // локальная переменная x: 4
//         cout << x << ", " << n1::x << ", " << n2::x << endl; // локальная переменная x: 4, n1::x: 1 ,n2::x: 2
//     }
//     using n2::x;
//     cout << x << endl; // n2::x: 2
//     other();
//     return 0;
// }
// void other()
// {
//     using namespace n2;
//     cout << x << endl; // n2::x: 2
//     {
//         int x = 4;
//         cout << x << ", " << n1::x << ", " << n2::x << endl; // локальная переменная x: 4, n1::x: 1 ,n2::x: 2
//     }
//     using n2::x;
//     cout << x << endl; // n2::x: 2
// }