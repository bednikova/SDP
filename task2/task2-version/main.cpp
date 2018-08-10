#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    /*
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
    */


    cout << "Test function IsFull: " << endl;

    BinTree* fullTree = buildFullBinTree();
    fullTree->display();
    cout << "IsFull: " << (IsFull(fullTree) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(fullTree) ? "true" : "false") << endl;


    BinTree* t8 = buildBinTree(true, 3);
    t8->display();
    cout << "IsFull: " << (IsFull(t8) ? "true" : "false") << endl;
    cout << "root " << t8->root->data << endl;
    cout << "IsBst: " << (IsBst(t8) ? "true" : "false") << endl;

    BinTree* t9 = buildBinTree(false, 3);
    t9->display();
    cout << "IsFull: " << (IsFull(t9) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(t9) ? "true" : "false") << endl;


    //test
    cout << "test1: " << endl;
    BinTree* test1 = buildFullBinTreeTest1();
    test1->display();
    cout << "root: " << test1->root->data << endl;
    cout << "IsFull: " << (IsFull(test1) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(test1) ? "true" : "false") << endl;

    cout << "test2: " << endl;
    BinTree* test2 = buildFullBinTreeTest2();
    test2->display();
    cout << "root: " << test2->root->data << endl;
    cout << "IsFull: " << (IsFull(test2) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(test2) ? "true" : "false") << endl;


    cout << "test3: " << endl;
    BinTree* test3 = buildFullBinTreeTest3();
    test3->display();
    cout << "root: " << test3->root->data << endl;
    cout << "IsFull: " << (IsFull(test3) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(test3) ? "true" : "false") << endl;


    cout << "test4: " << endl;
    BinTree* test4 = buildFullBinTreeTest4();
    test4->display();
    cout << "root: " << test4->root->data << endl;
    cout << "IsFull: " << (IsFull(test4) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(test4) ? "true" : "false") << endl;



    cout << "test5: " << endl;
    BinTree* test5 = buildFullBinTreeTest5();
    test5->display();
    cout << "root: " << test5->root->data << endl;
    cout << "IsFull: " << (IsFull(test5) ? "true" : "false") << endl;
    cout << "IsBst: " << (IsBst(test5) ? "true" : "false") << endl;
    return 0;
}
