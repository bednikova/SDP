#include <iostream>
#include "functions.h"

using namespace std;

int main()
{

    cout << "test1: " << endl;
    BinTree* test1 = buildBinTree(true, 10);
    test1->displayTree();
    cout << "IsBst: " << (IsBst(test1) ? "true" : "false" )<< endl;




    return 0;
}
