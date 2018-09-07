#include <iostream>
#include "struct.h"

using namespace std;

int main()
{
    Node* list = NULL;
    createList(list);
    printList(list);
    int n; cout << "Enter n = ";
    cin >> n;
    cout << endl;

    Node* newList = sortList(list, n);
    printList(newList);

    sortList1(list, n);

    printList(list);



    return 0;
}
