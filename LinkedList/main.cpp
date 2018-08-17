#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;
    list.insertFront(1);
    list.insertFront(3);
    list.insertEnd(5);

    cout << list << endl;

    list.removeFront();
    cout << list << endl;


    return 0;
}
