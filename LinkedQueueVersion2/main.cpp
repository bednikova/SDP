#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main()
{
    LinkedQueue<int> q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);

    while(!q.isEmpty())
    {
        cout << q.first() << " ";
        q.dequeue();
    }

    return 0;
}

