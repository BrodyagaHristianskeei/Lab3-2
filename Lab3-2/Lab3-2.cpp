#include <iostream>
//#include <iostream> Подкючает библиотеку input-output stream для вывода и ввода в консоль
#include <Windows.h>
//#include <Windows.h> позволяет работать с кирилицей в консоли, включает функции WinAPI sleep(), beep() и т.д
#include <String>
#include <functional>
using std::string;
using namespace std;

void printArray(int* begin, int* end, int* arr)
{//передадим указатели на первый и последний элементы массива
    int sum = 0;
    for (begin = &arr[0], end = &arr[4];
        begin < end; ++begin, --end)
        sum += *begin + *end;
    if (begin == end) sum += *begin;
    cout << sum << "\n";
}
int add(int x, int y) {

    return x + y;

}



int sub(int x, int y) {

    return x - y;

}

typedef int (*operation_p)(int, int);



operation_p operationType(char c) {
    if (c == '+') return add;
    if (c == '-') return sub;
    return nullptr;
};
int* test() {

    return new int(5);

}

int main()

{

    int array[5] = { 2,3,7,43,4 };

    printArray(begin(array), end(array), array);

    int (*ooperation)(int, int);

    ooperation = add;



    cout << ooperation(5, 7) << "\n";

    ooperation = sub;

    cout << ooperation(5, 7) << "\n";

    operation_p operation;
    if ((operation = operationType('+'))) {
        cout << operation(5, 7) << endl;
    }
    if ((operation = operationType('-'))) {
        cout << operation(5, 7) << endl;
    }
    int* pc1 = new int(5);// new возвращает указатель

    cout << pc1 << " = " << *pc1 << "\n";

    delete pc1;



    int* pc2 = test();


    //delete pc2; // Неправильно!Мы не можем освободить память дважды



    int* marray = new int[3]{ 0, 5, -5 };

    cout << marray[1] << "\n";

    for (int* i = marray; i < marray + 3; i++) {

        cout << *i << " ";

    }

    delete[] marray;

}