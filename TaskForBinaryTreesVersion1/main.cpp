#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    readTree();
    cout << endl << endl;

    BinaryTree tree;
    tree.insertBst(1);
    tree.insertBst(4);
    tree.insertBst(2);
    //tree.display();
    tree.displayTree();
    cout << endl << endl;

    cout << "\nSum nodes is: " << accumTree(&tree) << endl;

    BinaryTree *ptr = buildBinTree(4);
    cout << "\nBloomTree is: "  << endl;
    bloomTree(ptr);
    ptr->displayTree();
    cout << endl << endl;


    BinaryTree* ptrTree = new BinaryTree;
    ptrTree->insertBst(1);
    ptrTree->insertBst(4);
    ptrTree->insertBst(2);
    ptrTree->insertBst(6);
    ptrTree->insertBst(3);
    ptrTree->insertBst(29);
    cout << endl << endl;
    cout << "Original tree: \n";
    ptrTree->displayTree();
    cout << endl << endl;
    cout << "\nBloomTree is: "  << endl;
    bloomTree(ptrTree);
    ptrTree->displayTree();



    return 0;
}
