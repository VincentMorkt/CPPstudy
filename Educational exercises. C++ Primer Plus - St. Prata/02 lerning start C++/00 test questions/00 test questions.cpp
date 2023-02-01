// вопросы для самоконтроля
// Ответы на вопросы для самоконтроля по каждой главе можно найти в приложении к.

// 1. Как называются модули программ, написанных на языке С++?
// Функии

// 2. Что делает следующая директива препроцессора?
#include <iostream>
// Подключает заголовочный файл ввода-вывода, включающий классы istream & ostream, объекты и функции для ввода/вывода в консоль.

// 3. Что делает следующий оператор?
using namespace std;
// Включает пространство имён std в область видимости программы.

// 4. Какой оператор вы могли бы использовать, чтобы напечатать фразу "Hello, world" и перейти на новую строку?
int main()
{
    cout << "Hello, world" << endl;

// 5. Какой оператор вы могли бы использовать для создания переменной целочисленного типа по имени cheeses?
    int cheeses;

// 6. Какой оператор вы могли бы использовать, чтобы присвоить переменной cheeses значение 32?
    cheeses = 32;

// 7. Какой оператор вы могли бы использовать, чтобы прочитать значение, введенное с клавиатуры, и присвоить его переменной cheeses?
    cin >> cheeses;
    
// 8. Какой оператор вы могли бы использовать, чтобы напечатать фразу "We have Х varieties of cheese", в которой Х заменяется текущим значением переменной cheeses?
    cout << "We have " << cheeses << " varieties of cheese" << endl;
}
// 9. Что говорят вам о функциях следующие прототипы?
// int froop(double t); фунция возвращает int и принимает в качестве аргумента double
// void rattle(int n); функция ничего не возвращает и принимает int
// int prune(void); функция возвращает int и ничего не принимает

// 10. В каких случаях не используется ключевое слово return при определении функции?
// когда возвращаемый тип данных функции - void, то есть функция ничего не возвращает.

// 11. Предположим, что функция main() содержит следующую строку:
// cout << "Please enter your PIN: ";
// Также предположим, что компилятор сообщил о том, что cout является неизвестным идентификатором. Какова вероятная причина этого сообщения, и как выглядят способы решения проблемы?
// зона видимости пространства имён, содержащего cout, находится за пределами функции, в которой осуществляется его вызов. необходимо использовать std::cout или диррективу using