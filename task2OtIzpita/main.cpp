#include <iostream>
#include "struct.h"

using namespace std;

int main()
{
    Node* list = NULL;
    addNode(list, 'a');
    addNode(list, 'a', 'l');
    addNode(list, 'b', 'r');
    addNode(list, 'c', 'c');
    addNode(list->l, 's', 'l');
    addNode(list->l, 't', 'r');
    addNode(list->c, 'n', 'c');
    addNode(list->c, 'a', 'l');
    addNode(list->r, 'i', 'r');

    printTree(list);
    readTree(list);
    saveTree(list);



    return 0;
}
