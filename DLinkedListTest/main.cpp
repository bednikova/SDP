#include <iostream>
#include "DLinkedListTest.h"

using namespace std;


int main()
{
    DLinkedList<int> l;
    l.insert(2);
    l.insert(4);
    l.insert(6);
    cout << l;
    l.remove();
    cout << l;


    return 0;
}
