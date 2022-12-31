// 10. Измените код в листинге 16.9 (vect3.cpp) следующим образом.
// а. Добавьте член price в структуру Review.
// б. Для хранения вводимых данных используйте вектор (vector) объектов
// shared_ptr<Review> вместо вектора объектов Review. Помните, что
// shared_ptr должен быть инициализирован указателем, возвращенным операцией new.
// в. Вслед за этапом ввода данных реализуйте цикл, который предоставляет
// пользователю следующие варианты отображения книг: в исходном порядке,
// в алфавитном порядке, в порядке возрастания рейтинга, в порядке возрастания
// цены, в порядке уменьшения цены и возможность завершения программы.

// Один из возможных подходов может быть таким. После получения первоначальных
// введенных данных создайте еще один вектор указателей shared_ptr,
// инициализированный исходным массивом. Определите функцию operator<(),
// которая сравнивает указанные структуры, и примените ее для сортировки
// второго вектора так, чтобы shared_ptr были упорядочены по названиям книг,
// сохраненных в указанных объектах. Повторите процесс, чтобы получить вектор
// объектов shared_ptr, отсортированных по rating и price. Обратите внимание,
// что rbegin() и rend() избавляют от необходимости создания векторов с
// обратным порядком следования элементов.

// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cctype>

struct Review
{
    std::string title;
    int rating;
    double price; // а. Добавьте член price в структуру Review.
};
bool operator<(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool worseThan(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool cheaperThan(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool FillReview(std::shared_ptr<Review> &rr);
void ShowReview(const std::shared_ptr<Review> &rr);
void StreamClear()
{
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}
int main()
{
    using namespace std;
    // б. Для хранения вводимых данных используйте вектор (vector) объектов
    // shared_ptr<Review> вместо вектора объектов Review.
    vector<shared_ptr<Review>> books;

    while (true)
    { // Помните, что shared_ptr должен быть инициализирован указателем, возвращенным операцией new.
        shared_ptr<Review> temp(new Review());
        if (FillReview(temp))
            books.push_back(temp);
        else
            break;
    }
    if (books.size() > 0)
    {
        // в. Вслед за этапом ввода данных реализуйте цикл, который предоставляет
        // пользователю следующие варианты отображения книг: в исходном порядке,
        // в алфавитном порядке, в порядке возрастания рейтинга, в порядке возрастания
        // цены, в порядке уменьшения цены и возможность завершения программы.
        cout << "\nThank you. You entered the following " << books.size() << " titles\n\n"
             << "showing list... choose sorting\n"
             << "O: original        A: titel            R: rating\n"
             << "C: first cheaper   E: first expensive  Q: quit\n"
             << "choice: ";
        char choice;
        while (cin.get(choice))
        {
            StreamClear();
            choice = tolower(choice);           // перевод буквы в нижний регистр
            if (choice == 'q' || choice == '6') // если q то выход (прерывание цикла)
                break;
            cout << endl;
            vector<shared_ptr<Review>> sortBooks(books);
            switch (choice)
            {
            case '1':
            case 'o': // оригинальный порядок
                cout << "Original order\n"
                     << "Rating\tCoast\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '2':
            case 'a':
                sort(books.begin(), books.end());
                cout << "Sorted by title\n"
                     << "Rating\tCoast\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '3':
            case 'r':
                sort(books.begin(), books.end(), worseThan);
                cout << "Sorted by ratings\n"
                     << "Rating\tCoast\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '4':
            case 'c':
                sort(books.begin(), books.end(), cheaperThan);
                cout << "Sorted by coast (first cheaper)\n"
                     << "Rating\tCoast\tBook\n";
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '5':
            case 'e':
                sort(books.begin(), books.end(), cheaperThan);
                cout << "Sorted by coast (first expensive)\n"
                     << "Rating\tCoast\tBook\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
                break;

            default:
                cout << "Bad input! Try again\n";
                break;
            }
            cout << "\nchoose sorting\n"
                 << "O: original        A: titel            R: rating\n"
                 << "C: first cheaper   E: first expensive  Q: quit\n"
                 << "choice: ";
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    cin.get();
    return 0;
}

bool operator<(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool cheaperThan(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(std::shared_ptr<Review> &rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr->rating;
    if (!std::cin)
    {
        StreamClear();
        return false;
    }
    // get rid of rest of input line
    StreamClear();
    std::cout << "Enter price: ";
    std::cin >> rr->price;
    if (!std::cin)
    {
        StreamClear();
        return false;
    }
    // get rid of rest of input line
    StreamClear();
    return true;
}

void ShowReview(const std::shared_ptr<Review> &rr)
{
    std::cout << rr->rating << '\t' << rr->price << '\t' << rr->title << std::endl;
}
