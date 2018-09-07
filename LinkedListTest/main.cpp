#include <iostream>
#include "LinkedListTest.h"

using namespace std;

int main()
{

    LinkedList<int> l;

    l.insert(3);
    l.insert(2);
    l.insert(1);
    l.insertEnd(4);
    cout << l;

    l.remove();
    cout << l;

    return 0;
}
