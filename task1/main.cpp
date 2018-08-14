#include <iostream>
#include "struct.h"

using namespace std;

int main()
{
    Node* list = NULL;
    addRandomNodes(list, 10);

    cout << "List: ";
    printList(list);
    cout << endl;

    Node* newList = NULL;
    Rearrange(list, newList);

    cout << "\nRearranged List: ";
    printList(newList);
    cout << endl;

    return 0;
}
