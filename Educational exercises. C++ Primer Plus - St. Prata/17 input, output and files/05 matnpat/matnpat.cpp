// 5. Мэт (Mat) и Пэт (Pat) хотят пригласить своих друзей на вечеринку - почти так
// же, как они это делали в упражнении 8 из главы 16, за исключением того, что
// теперь им нужна программа, использующая файлы. Они просят вас написать
// программу, которая должна выполнпть перечисленные ниже действия.
// • Считывать список друзей Мэта из текстового файла mat.dat,
// в котором в каждой строке указан один друг. Имена сохраняются
// в контейнере и затем отображаются в отсортированном виде.
// • Считывать список друзей Пэт из текстового файла раt.dat,
// в котором в каждой строке указан один друг.
// Имена сохраняются в контейнере и затем отображаются в отсортированном виде.
// • Объединить эти два списка, исключая дубликаты, и сохранить результат в
// файле matnpat.dat, по одному другу в строке.

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
    using namespace std;

    ifstream matfin("mat.dat");
    ifstream patfin("pat.dat");
    if (!matfin.is_open() || !patfin.is_open())
    {
        cerr << "Error. files can not opened";
        exit(EXIT_FAILURE);
    }

    set<string> Mat, Pat, All;
    string Mat_temp, Pat_temp;

    while (matfin)
    {
        getline(matfin, Mat_temp);
        Mat.insert(Mat_temp);
    }
    cout << "\tMat list:\n";
    copy(Mat.begin(), Mat.end(), ostream_iterator<string, char>(cout, "\n"));

    while (patfin)
    {
        getline(patfin, Pat_temp);
        Pat.insert(Pat_temp);
    }
    cout << "\n\tPat list:\n";
    copy(Pat.begin(), Pat.end(), ostream_iterator<string, char>(cout, "\n"));

    copy(Mat.begin(), Mat.end(), insert_iterator<set<string>>(All, All.end()));
    copy(Pat.begin(), Pat.end(), insert_iterator<set<string>>(All, All.end()));

    ofstream fout("matnpat.dat");
    set<string>::iterator itr;
    for (itr = All.begin(); itr != All.end(); itr++)
        fout << *itr << endl;
    cin.get();
}