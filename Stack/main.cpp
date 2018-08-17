#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);


    cout << stack.top() << " ";
    stack.pop();

    cout << stack.top() << " ";
    stack.pop();

    cout << stack.top() << " ";
    stack.pop();

    cout << stack.top() << " ";
    stack.pop();



    return 0;
}
