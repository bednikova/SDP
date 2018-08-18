#include <iostream>
#include "struct.h"

using namespace std;

int main()
{
    Node* list = NULL;

    addRandom(list, 5);
    cout << "List: ";
    printList(list);
    cout << endl;
    //Node* newList = NULL;
    //Rearrange(list, newList);
    cout << "Rearrange list: ";
    Rearrange(list, list);
    printList(list);
    //printList(newList);
    cout << endl;


    return 0;
}
