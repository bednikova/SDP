#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main()
{
    LinkedQueue<int> queue;
    queue.enqueue(3);
    queue.enqueue(55);
    queue.enqueue(455);

    while(!queue.isEmpty())
    {
        cout << queue.first() << " ";
        queue.dequeue();
    }
    return 0;
}
