#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q;

    q.enqueue(33);
    q.enqueue(455);

    while(!q.isEmpty())
    {
        cout << q.first() << " ";
        q.dequeue();
    }


    return 0;
}
