#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> linkedStack;
    linkedStack.push(1);
    linkedStack.push(5);

    cout << linkedStack.top() << " ";
    linkedStack.pop();
    cout << linkedStack.top() << " ";
    linkedStack.pop();
    return 0;
}
