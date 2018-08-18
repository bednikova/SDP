#include <iostream>
#include "DLinkedList.h"

using namespace std;

int main()
{
    DLinkedList<int> list;

    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "List: " << list << endl;
    list.remove();
    cout << "Remove element, list: " << list << endl;


    return 0;
}
