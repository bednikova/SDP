#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << " ";
    stack.pop();
    cout << stack.top() << " ";
    stack.pop();
    cout << stack.top() << " ";
    stack.pop();


    return 0;
}
