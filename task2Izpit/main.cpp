#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Node* tree = NULL;
    addNode(tree, 'm', 'l');
    addNode(tree, 'm', 'l');
    addNode(tree, 'i', 'c');
    addNode(tree, 'h', 'r');
    addNode(tree->left, 'm', 'l');
    addNode(tree->left, 'i', 'c');
    addNode(tree->left, 's', 'r');
    addNode(tree->central, 'h', 'c');
    addNode(tree->right, 'a', 'r');

    //createTree(tree);
    printTree(tree);

    cout << endl;

    readTree(tree);

    saveTree(tree);

    return 0;
}
