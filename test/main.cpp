#include <iostream>
#include "dList.h"
#include "List.h"

using namespace std;

int main()
{

    List<int> l;
    l.insertFront(3);
    l.insertEnd(4);
    l.insertFront(2);
    cout << l;
    l.removeFront();
    cout << l;


    dList<int> l1;
    l1.insert(3);
    l1.insert(4);
    l1.insert(2);
    cout << l1;
    l1.remove();
    cout << l1;

    return 0;
}
