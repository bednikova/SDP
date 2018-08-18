#include <stdlib.h>

struct Node
{
    int data;
    Node* next;

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void addNode(Node*& list, int data)
{
    Node* newNode = new Node(data, NULL);
    if(list == NULL)
    {
        list = newNode;
    }
    else
    {
        Node* temp = list;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void addRandom(Node*& list, int nodeCount)
{
    for(int i = 0; i < nodeCount; ++i)
    {
        addNode(list, rand()%100);
    }
}


void printList(Node* list)
{
    while(list != NULL)
    {
        std::cout << list->data << " ";
        list = list->next;
    }
}

void Rearrange(Node* list, Node*& newList)
{
    Node* oddList = NULL;
    Node* evenList = NULL;


    //Split list

    while(list != NULL)
    {
        if(list->data % 2 == 0)
        {
            addNode(evenList, list->data);
        }
        else
        {
            addNode(oddList, list->data);
        }

        list = list->next;
    }

    //linked newList

    newList = evenList;
    while(evenList->next != NULL)
    {
        evenList = evenList->next;
    }
    evenList->next = oddList;
}
