#include <iostream>
#include "struct.h"

using namespace std;


int main()
{
   // Node *head, *tail;
    //createNode(3, head, tail);
    //createNode(4, head, tail);
    //createNode(33, head, tail);
    //createNode(41, head, tail);
    //createNode(6, head, tail);
    //createNode(7, head, tail);
    //createNode(8, head, tail);
    //createNode(1, head, tail);

    createNode(1);
    createNode(12);
    createNode(3);
    createNode(3);
    createNode(5);
    createNode(4);
    createNode(1);

    cout << "List: ";
    printNodes(head);
    cout << endl;
    //printNodes(head);
    xxx = head;  // copy
    //printNodes(xxx);

   // Node *headEven, *tailEven;
    //Node *headOdd, *tailOdd;

    //Rearrange(head, headEven, tailEven, headOdd, tailOdd);
    Rearrange();  //polzva kopieto za sysdavane na headEven and headOdd

    //cout << endl;
    //printNodes(headEven);

    //cout << endl;
    //printNodes(headOdd);

    cout << endl;
    cout << "Reorder list: ";
    printNodes(head);

    cout << endl;
    cout << endl;

    return 0;
}
