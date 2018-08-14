#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
/*
    cout << "test1: " << endl;
    BinTree* test1 = buildBinTree(true, 10);
    test1->displayTree();
    cout << "IsBst: " << (IsBst(test1) ? "true" : "false" )<< endl;
*/
    cout << "test2: " << endl;
    BinTree* test2 = buildBinTree(false, 7);
    test2->displayTree();
    cout << "ReduceToBst: " << endl;
    cout << endl;
    ReduceToBst(test2);

    cout << endl << "Final tree \n";
    test2->displayTree();




    return 0;
}
