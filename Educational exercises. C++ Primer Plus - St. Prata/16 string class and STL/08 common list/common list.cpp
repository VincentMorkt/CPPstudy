// 8. Мэт и Пэт хотят пригласить своих друзей на вечеринку.
// Они просят вас написать программу, которая делает следующее.
// • Позволяет Мэту ввести список имен его друзей.
// Имена сохраняются в контейнере и затем отображаются в отсортированном порядке.
// • Позволяет Пэт ввести список ее друзей.
// Имена сохраняются во втором контейнере и затем отображаются в отсортированном порядке.
// • Создает третий контейнер, который объединяет эти два списка,
// исключает дубликаты и отображает содержимое этого контейнера.
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

void setEnter(std::set<std::string> &st);

int main()
{
    using namespace std;
    set<string> Mat, Pat;
    cout << "Enter Mat frends names <empty to stop>:\n";
    setEnter(Mat);
    cout << "Enter Pat frends names <empty to stop>:\n";
    setEnter(Pat);
    copy(Mat.begin(), Mat.end(), insert_iterator<set<string>>(Pat,Pat.end()));
    // set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), All); // не работает, нет перегруженных операций сравнения для string (втф)
    cout << "Common list: " << endl; 
    copy(Pat.begin(), Pat.end(), ostream_iterator<string, char>(cout, "\n"));
    cin.get();
    return 0;
}
void setEnter(std::set<std::string> &st)
{
    while (true)
    {
        std::string str;
        getline(std::cin, str);
        if (str.size() == 0)
            return;
        st.insert(str);
    }
}