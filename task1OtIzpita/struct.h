#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data = NULL, Node* next = NULL) : data(data), next(next) {}
};

void addNode(Node*& list, int x)
{
    Node* newNode = new Node(x);
    if(!list)
    {
        list = newNode;
    }
    else
    {
        Node* temp = list;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void destroy(Node* list)
{
    Node* temp = NULL;
    while(list)
    {
        temp = list;
        list = list->next;
        delete temp;
    }
}

void createList(Node*& list)
{
    int n; char c;
    do
    {
        cout << "Enter element: ";
        cin >> n;
        addNode(list, n);
        cout << "\nAdd next element? y or n: ";
        cin >> c;
        cout << endl;
    }while(c == 'y');
}

void printList(Node* list)
{
    Node* temp = list;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sortList1(Node*& list, int n)
{
    Node* temp = NULL;
    Node* newList = NULL;
    int i = 0;
    while(i < n)
    {
        temp = list;
        while(temp)
        {

            if(temp->data % n == i)
            {
                addNode(newList, temp->data);
            }

            temp = temp->next;
        }
        i++;
    }

    destroy(list);
    list = newList;
}

Node* sortList(Node* list, int n)
{
    Node* temp = NULL;
    Node* newList = NULL;

    int i = 0;
    while(i < n)
    {
        temp = list;
        while(temp)
        {
            if(temp->data % n == i)
            {
                addNode(newList, temp->data);
            }
            temp = temp->next;
        }
        ++i;
    }

    return newList;
}
