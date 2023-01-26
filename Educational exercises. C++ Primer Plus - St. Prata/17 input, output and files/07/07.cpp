// 7. Ниже представлена часть программы, которая читает клавиатурный ввод в вектор объектов string, сохраняет строковое содержимое
// (не объекты!) в файле, а затем копирует содержимое файла обратно в вектор объектов string:
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

void ShowStr(const std::string &str)
{
    std::cout << str << std::endl;
}

class Store
{
private:
    std::ofstream &fout;
public:
    Store(std::ofstream &f) : fout(f){};
    void operator()(const std::string &str)
    {
        std::size_t len = str.length();
        fout.write((char *)&len, sizeof(std::size_t));
        fout.write(str.data(), len);
    }
};

void GetStrs(std::ifstream &fin, std::vector<std::string> &vect)
{
    std::cout << "GetStrs working..."; // !
    int numstr = 0;
    vect.clear();
    while (fin)
    {
        std::string temp;
        std::size_t len;
        fin.read((char *)&len, sizeof(std::size_t));
        std::cout << len;
        for (int i = 0; i < len; i++)
        {
            char ch;
            fin.read(&ch, sizeof(char));
            std::cout << ch; // !
            temp.push_back(ch);
        }
        vect.push_back(temp);
        numstr++;
    }
}

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    // Получить строки
    cout << "Enter strings (empty line to quit):\n"; // запрос на ввод строк
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);

    cout << "Here is your input.\n";
    // вывод в веденных строк
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // Восстановить содержимое файла
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n"; // не удается открыть файл для ввода
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n"; // строки, прочитанные из файла
    for_each(vistr.begin(), vistr.end(), ShowStr);
    cin.get();
    return 0;
}

// Обратите внимание, что файл открывается в бинарном формате и требуется, чтобы ввод-вывод осуществлялся методами read() и write().
// стается сделать немного, как перечислено ниже.
// • Написать функцию void ShowStr(const string &), которая отображает объект string с последующим символом перевода строки.
// • Написать функтор Store, который записывает строковую информацию в файл. Конструктор Store должен указывать объект ifstream,
// а перегруженная функция operator()(const string &) должна указывать строку, подлежащую записи.

// Приемлемый подход состоит в записи в файл сначала размера строки, а затем - ее содержимого.
// Например, если len содержит размер строки, можно было бы использовать следующие операторы:
// os.write((char *)&len, sizeof(std::size_t)); // сохранить длину
// os.write(s.data(), len);                     // сохранить символы
// Член data() возвращает указатель на массив, который содержит символы строки. Он подобен члену с_str(), за исключением того,
// что последний добавляет нулевой символ.
// • Написать функцию GetStrs(), которая восстанавливает информацию из файла. Она может использовать read() для получения размера строки
// и затем применять цикл для чтения указанного количества символов из файла, добавляя их в изначально пустую временную строку.
// Поскольку данные объекта string - закрытые, для извлечения данных в строку должен использоваться метод класса вместо считывания их напрямую в нее.
