// 3. Выполните упражнение 1 из главы 9, но замените показанный там код подходящим объявлением класса golf. 
// Замените setgolf(golf & , const char *, int) конструктором с соответствующими аргументами для выполнения инициализации.
// Оставьте интерактивную версию setgolf(), но реализуйте ее с использованием этого конструктора.
// (Например, в коде setgolf() получите данные, передайте их конструктору для создания временного объекта 
// и присвойте временный объект вызвавшему, представленному через * this.) 

// 1. Имеется следующий заголовочный файл:
// golf.h -- для ре 9-1.срр объявление класса и прототипы функций

#ifndef GOLF_H_
#define GOLF_H_
const int Len = 40;

class golf // объявление класса
{
private:
    char fullname[Len];
    int handicap;

public:
    
    // Неинтерактивная версия:
    // метод присваивает структуре типа golf имя игрока и его гандикап (фору), используя передаваемые ей аргументы
    golf(const char *name = "", int hc = 0);

    // Интерактивная версия:
    // функция предлагает пользователю ввести имя и гандикап, присваивает элементам структуры g введенные значения;
    // возвращает 1, если введено имя, и 0, если введена пустая строка
    bool setGolf();

    // Функция устанавливает новое значение гандикапа
    void setHandicap(int hc);

    // Функция отобража ет содержимое структуры типа golf
    void showGolf() const;
    
    // метод проверяет, пуст ли список
    bool isEmpty() const;
};

// Функция очистки потока ввода
void ClearIStream(void);

#endif