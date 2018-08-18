#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    int* arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 6;
    arr[4] = 4;
    arr[5] = 3;
    BinarySearchTree<int> binTree(arr, 3);
    binTree.printTree();

    return 0;
}
