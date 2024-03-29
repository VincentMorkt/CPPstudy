// 1. Имеется следующий заголовочный файл:
// golf.h -- для ре 9-1.срр
#ifndef GOLF_H_
#define GOLF_H_
const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};
// Неинтерактивная версия:
// функция присваивает структуре типа golf имя игрока и его гандикап (фору), используя передаваемые ей аргументы
void setgolf(golf &g, const char *name, int hc);
// Интерактивная версия:
// функция предлагает пользователю ввести имя и гандикап, присваивает элементам структуры g введенные значения;
// возвращает 1, если введено имя, и 0, если введена пустая строка
int setgolf(golf &g);

// Функция устанавливает новое значение гандикапа
void handicap(golf &g, int hc);

// Функция отобража ет содержимое структуры типа golf
void showgolf(const golf &g);

// Функция очистки потока ввода
void ClearIStream(void);
#endif