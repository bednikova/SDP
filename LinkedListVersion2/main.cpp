#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    list.push(5);
    list.push(7);

    cout << list.top() << " ";
    list.pop();
    cout << list.top() << " ";
    list.pop();

    return 0;
}
