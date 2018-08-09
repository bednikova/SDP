#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    BinTree* t = buildBinTree(true, 10);
    t->display();
    cout << (IsBst(t) ? "true" : "false") << endl;

    BinTree* t1 = buildBinTree(false, 10);
    t1->display();
    cout << (IsBst(t1) ? "true" : "false") << endl;

    return 0;
}
