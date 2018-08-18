#include <iostream>
#include "BinarySearchTree.h"


using namespace std;

int main()
{
    BinarySearchTree<int> t;

    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.displayTree();
    cout << endl << endl;
    t.remove(20);
    t.displayTree();
    cout << endl << endl;
    t.remove(25);
    t.displayTree();
    cout << endl << endl;
    t.remove(30);
    t.displayTree();
    cout << endl << endl;

    return 0;
}
