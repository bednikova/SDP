#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray<int> array;
    array.add(1);
    array.add(45);
    array.add(27);

    cout << array << endl;
    cout << array[2];


    return 0;
}
