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


    cout << "Test with empty tree! \n";
    BinTree* t2 = buildBinTree(true, 0);
    t2->display();
    cout << (IsBst(t2) ? "true" : "false") << endl;

    BinTree* t3 = buildBinTree(false, 0);
    t3->display();
    cout << (IsBst(t3) ? "true" : "false") << endl;


    BinTree* t4 = buildBinTree(true, 1);
    t4->display();
    cout << (IsBst(t4) ? "true" : "false") << endl;


    BinTree* t5 = buildBinTree(false, 1);
    t5->display();
    cout << (IsBst(t5) ? "true" : "false") << endl;



    cout << "Test function IsFull: " << endl;
    BinTree* t6 = buildBinTree(true, 7);
    t6->display();
    cout << (IsFull(t6) ? "true" : "false") << endl;


    BinTree* t7 = buildBinTree(false, 7);
    t7->display();
    cout << (IsFull(t7) ? "true" : "false") << endl;


    BinTree* t8 = buildBinTree(true, 6);
    t8->display();
    cout << (IsFull(t8) ? "true" : "false") << endl;


    BinTree* t9 = buildBinTree(false, 6);
    t9->display();
    cout << (IsFull(t9) ? "true" : "false") << endl;

    return 0;
}
