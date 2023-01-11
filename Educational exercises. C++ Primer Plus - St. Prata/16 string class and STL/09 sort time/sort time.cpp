// 9. По сравнению с массивом связный список отличается более простым добавлением и
// удалением элементов, но медленной сортировкой. Поэтому возникает вопрос:
// возможно, было бы быстрее скопировать список в массив, отсортировать
// массив и скопировать отсортированный результат обратно в список, чем просто
// использовать алгоритм списка для сортировки. (Но это может быть связано с
// наличием большего объема памяти.) Проверьте гипотезу о более быстром выполнении задачи,
// применив следующий подход.
// а. Создайте большой объект vi0 типа vector<int>, используя rand() для задания начальных значений.
// б. Создайте второй объект vi типа vector<int> и объект li типа list<int>
// того же размера, что и исходный, и инициализируйте их значениями исходного вектора.
// в. Замерьте время, требуемое программе для сортировки vi с помощью алгоритма sort() из STL,
// а затем время, необходимое для сортировки li посредством метода list.sort().
// г. Переустановите li неотсортированным содержимым viО.
// Замерьте время выполнения смешанной операции копирования li в vi,
// сортировки vi и копирования результата обратно в li.

// Для измерения времени выполнения этих операций можно использовать
// clock() из библиотеки ctime. Как показано в листинге 5.14,
// для запуска первого таймера можно применять следующий оператор:
// clock_t start = clock();
// Для получения прошедшего времени в конце операции используйте следующий
// оператор:
// clock_t end = clock();
// cout << (double)(end-start)/CLOCKS_PER SEC;

// Вне всяких сомнений, этот тест показателен, поскольку результаты будут зависеть
// от ряда факторов, в том числе объема доступной памяти, применения
// многопроцессорной обработки и размеров массива или списка.
// (С увеличением количества сортируемых элементов можно ожидать большего увеличения
// эффективности массива по сравнению со списком.) Кроме того, при наличии
// выбора между стандартной сборкой и окончательной сборкой, следует выбирать
// окончательную сборку. В современных высокоскоростных компьютерах
// для получения репрезентативных результатов необходимо использовать массив
// максимально возможного размера. Например, можно иметь 100 000, 1 000 000 и
// 10 000 000 элементов.

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main()
{
     using namespace std;
     srand(time(0));

     cout << "enter vector size <q to quit>: ";
     long long size;
     cin >> size;
     cin.get();

     vector<int> vi0;
     cout << "initialization started!\n\n";
     for (long long i = 0; i < size; i++)
          vi0.push_back(rand());

     vector<int> vi(vi0);
     list<int> li(vi0.begin(), vi0.end());

     cout << "sort<vector<int>>(begin, end) started!\n";
     clock_t startVI = clock();
     sort(vi.begin(), vi.end());
     clock_t endVI = clock();
     double vectorSortTime = (double)(endVI - startVI) / CLOCKS_PER_SEC;
     cout << "time of operation: " << vectorSortTime << endl
          << endl;

     cout << "list<int>.sort() started!\n";
     clock_t startLI = clock();
     li.sort();
     clock_t endLI = clock();
     double listSortTime = (double)(endLI - startLI) / CLOCKS_PER_SEC;
     cout << "time of operation: " << listSortTime << endl
          << endl;

     copy(vi0.begin(), vi0.end(), li.begin());

     cout << "copy list to vector, sort<vector> and copy back started!\n";
     clock_t startLIcopy = clock();
     vector<int> lisort(li.begin(), li.end());
     sort(lisort.begin(), lisort.end());
     copy(lisort.begin(), lisort.end(), li.begin());
     clock_t endLIcopy = clock();
     double listCopySortTime = (double)(endLIcopy - startLIcopy) / CLOCKS_PER_SEC;
     cout << "time of operation: " << listCopySortTime << endl
          << endl;

     cout << "                               vector sort time: " << vectorSortTime << endl
          << "                                 list sort time: " << listSortTime << endl
          << "list (copy to vector method) copy and sort time: " << listCopySortTime << endl;

     cin.get();

     return 0;
}
