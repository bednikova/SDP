#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> list;

    list.push(5);
    list.push(7);

    cout << list.top() << " ";
    list.pop();
    cout << list.top() << " ";
    list.pop();

    return 0;
}
