// 1. Что производный класс наследует от базового класса?
// Наследуются все члены базового класса кроме конструктора, деструктора, операций копирования и присваивания и дружественных функций.
// Закртытые члены базового класса доступны производному классу только через методы базового класса
// Защищённые и открытые члены наследуются напрямую, с таким же доступом, как и в базовом классе

// 2. Что производный класс не наследует от базового класса?
// Конструкторы, деструкторы, операторы присваивания и копирования, дружественные функции

// 3. Предположим, что возвращаемый тип для функции baseDМA::operator=()определен как void, а не baseDМA &.
// Как это повлияет на программу? Что случится, если возвращаемым типом будет baseDМA, а не baseDМA &?
// с возвращаемым типом void функция будет работать, но будет невозможно использовать несколько операций = в одном операторе (baseDMA base1 = base2 = base3 = base0; - невозможно)
// возврат объекта уменьшает производительность (объект всегда будет больше, чем адресс объекта), но в некоторых случаях необходимо возвращать именно объект
// (адресс локального объекта возвращать нельзя, поскольку он будет уничтожен после завершения метода)

// 4. В каком порядке вызываются конструкторы и деструкторы класса при создании и удалении объекта производного класса?
// При создании - сначала вызывается конструктор базового класса, потом конструктор производного класса. Деструкторы вызываются наоборо, сначала производного класса, потом базового.

// 5. Если производный класс не добавляет члены данных в базовый класс, то нужны ли конструкторы для производного класса?
// Да, нужны, конкструкторы не наледуются.

// 6. Предположим, что и в базовом, и в производном классе определен метод с одним и тем же именем, и производный класс вызывает этот метод. Который метод будет вызван?
// Будет вызван метод производного класса

// 7. В каких случаях производный класс должен определять операцию присваивания?
// В таких же ситуациях, как и в обычном классе - когда членами-данными являются указатели, конструкторы используют new / new [] или в других ситуациях, когда автоматически определённая операция присваивания не подходит.

// 8. Можно ли присвоить адрес объекта производного класса указателю на базовый класс?
// Можно ли присвоить адрес объекта базового класса указателю на производный класс?
// 1. Да, это позволит использовать все методы базового класса с производным, и виртуальные методы в соответствии с наличием их определений.
// 2. Только с помощью явного преобразования, и это нужно делать с осторожностью (не применять методы производного класса с такими указателями)

// 9. Можно ли присвоить объект производного класса объекту базового класса?
// Можно ли присвоить объект базового класса объекту производного класса?
// 1. Да, хотя все члены производного класса присвоены не будут (само собой).
// 2. Да, но для этого нужно определить операцию присваивания с аргументов типа базового класса в производном классе, или операцию преобразования типа из базового в производный.

// 10. Предположим, что определена функция, которая принимает в качестве аргумента ссылку на объект базового класса.
// Почему эта функция может также использовать в качестве аргумента объект производного класса?
// Потому что указатели и ссылки на базовый тип могут указывать и на производный тип.

// 11. Предположим, что определена функция, которая принимает в качестве аргумента объект базового класса (т.е. функция передает объект базового класса по значению).
// Почему эта функция может также использовать в качестве аргумента объект производного класса?
// Потому что будет вызван помощью конструктор копирования базового класса. Аргументом такого конструктора будет ссылка на базовый класс, которая может указывать на производный.

// 12. Почему обычно лучше передавать объекты по ссылке, а не по значению?
// Это экономит ресурсы системы, поскольку нужно передать только адресс (один байт), а не большое количество байт данных объекта. Также это позволяет передавать адресса производных объектов и использовать виртуальные функции.

// 13. Предположим, что Corporation - базовый класс, а PublicCorporation - производный.
// Допустим также, что в каждом из этих классов определен метод head(), ph является указателем на тип Corporation, а переменной ph присвоен
// адрес объекта PublicCorporation. Как интерпретируется ph->head(), если в базовом классе метод head() определен как:
// а. обычный не виртуальный метод; -- как вызов метода базового класса, поскольку указатель указывает на базовый класс а функция не является виртуальной
// б. виртуальный метод. -- как вызов метода производного класса, поскольку программа ориентируется на тип объекта, а не на тип указателя, при вызове виртуальных функций.

// 14. Есть ли ошибки в следующем коде, и если есть, то какие?
// class Kitchen
// {
// private:
//     double kit_sq_ft;

// public:
//     Kitchen() { kit_sq_ft = 0.0; }
//     virtual double area() const { return kit_sq_ft * kit_sq_ft; } // квадратные футы возводятся в квадрат, и получаются гиперкубические футы? площадь в пятом измерении? ЧТО ЗА БЕЗУМИЕ? 
// };
// class House : public Kitchen
// {
// private:
//     double all_sq_ft; //

// public:
//     House() { all_sq_ft += kit_sq_ft; } // в производном классе у нас нет доступа к закрытым данным базого класса. единственное что можно сделать - {all_sq_ft += sqrt(Kitchen::area())}
//     double area(const char *s) const    // метод скрывает Kitchen::area() базового класса, сигнатура должна быть одинаковой, да и само поведение метода отличается, нет смысла в полиморфизме
//     {
//         cout << s;
//         return all_sq_ft;
//     }
// };
// В целом это выглядит как одна большая ошибка, дом не является кухней, а содержит кухню, делать его производным классом неправильно. 
// Одноимённые методы делают концептуально разные вещи, не говоря о том, что производный скрывает базовый, не говоря уже о гиперкубах.