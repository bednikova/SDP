#include <iostream>

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

void createList(Node*& list)
{
    int n;
    char c;

    do
    {
        std::cout << "Enter element: ";
        std::cin >> n;
        addNode(list, n);
        std::cout << std::endl << "Add next element: y or n: ";
        std::cin >> c;
        std::cout << std::endl;

    }while(c == 'y');
}


void printNode(Node* list)
{
    while(list)
    {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << std::endl;
}


void destroy(Node* list)
{
    Node* temp;
    while(list)
    {
        temp = list;
        list = list->next;
        delete temp;
    }
}


Node* sortList(Node* list, int n)
{
    Node* newList = NULL;
    Node* temp;
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
