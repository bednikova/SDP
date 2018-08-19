#include "struct.h"

using namespace std;

int main()
{
    Node* list = NULL;
    addRandomNode(list, 6);
    cout << "List: ";
    printList(list);

    Node* newList = NULL;
    newList = Duplicate(list);
    cout << "New list: ";
    printList(newList);


    //test
    Node* listTest = NULL;
    addNode(1,listTest);
    addNode(4,listTest);
    addNode(30,listTest);
    addNode(11,listTest);
    addNode(5,listTest);
    addNode(20,listTest);

    cout << "listTest: ";
    printList(listTest);

    Node* newListTest = NULL;
    newListTest = Duplicate(listTest);
    cout << "New listTest: ";
    printList(newListTest);


    return 0;
}
