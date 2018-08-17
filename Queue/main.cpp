#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    while(!queue.isEmpty())
    {
        cout << queue.first() << " ";
        queue.dequeue();
    }


    return 0;
}
