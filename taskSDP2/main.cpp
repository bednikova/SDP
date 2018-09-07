#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Node* tree = NULL;
    addNode(tree, 'k');
    addNode(tree, 'l', 'l');
    addNode(tree, 'c', 'c');
    addNode(tree, 'r', 'r');
    //addNode(tree->left, 'm', 'r');
    addNode(tree->left, 'c', 'c');
    //addNode(tree->left, 'm', 'l');
    addNode(tree->central, 'a', 'r');
    //addNode(tree->central, 'n', 'c');
    //addNode(tree->central, 'n', 'l');
    //addNode(tree->right, 's', 'r');
    //addNode(tree->right, 's', 'c');
    addNode(tree->right, 't', 'l');

    saveInFile(tree);
    printTree(tree);
    cout << endl << "Visochinata na dyrvoito: " << heightTree(tree);
    cout << endl << endl;
    readTree(tree);

    return 0;
}
