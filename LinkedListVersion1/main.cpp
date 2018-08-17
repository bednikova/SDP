#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> linkedStack;
    linkedStack.push(1);
    linkedStack.push(5);

    cout << linkedStack.top() << " ";
    linkedStack.pop();
    cout << linkedStack.top() << " ";
    linkedStack.pop();
    return 0;
}
