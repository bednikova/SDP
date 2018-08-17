#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<double> q;
    q.enqueue(3.33);
    q.enqueue(34.22);

    while(!q.isEmpty())
    {
        cout << q.first() << " ";
        q.dequeue();
    }

    return 0;
}
