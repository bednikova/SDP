#include <iostream>
#include "struct.h"

using namespace std;

int main()
{
    Node* list = NULL;
    createList(list);
    printNode(list);
    //destroy(list);

    int n;
    cout << "Enter n = ";
    cin >> n;
    Node* newList = NULL;
    newList = sortList(list, n);
    printNode(newList);


    return 0;
}
