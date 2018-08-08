#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    BinTree t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();

    IsBst(&t);

    return 0;
}
