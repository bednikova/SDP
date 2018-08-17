#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(4);

    cout << q.first() << " ";
    q.dequeue();
    cout << q.first() << " ";
    q.dequeue();


    return 0;
}
