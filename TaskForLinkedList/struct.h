#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int Data;
    Node* pPrev;
    Node* pNext;
};

void addNode(int data, Node*& list)
{
    Node* newNode = new Node;
    if(list == NULL)
    {
        list = newNode;
        newNode->Data = data;
        newNode->pNext = NULL;
        newNode->pPrev = NULL;
    }
    else
    {
        Node* temp = list;
        while(temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = newNode;
        newNode->Data = data;
        newNode->pPrev = temp;
        newNode->pNext = NULL;
    }
}

void addRandomNode(Node*& list, int nodeCount)
{
    for(int i = 0; i < nodeCount; ++i)
    {
        addNode(rand()%100, list);
    }
}

void printList(Node* list)
{
    while(list != NULL)
    {
        cout << list->Data << " ";
        list = list->pNext;
    }

    cout << endl;
}


Node* Duplicate(const Node* pFirst)
{
    Node* newList = NULL;// = pFirst;
    while(pFirst != NULL)
    {
        if(pFirst->Data % 2 == 0)
        {
            addNode(pFirst->Data/2, newList);
        }
        else
        {
            addNode(pFirst->Data, newList);
        }

        pFirst = pFirst->pNext;
    }

    return newList;
}

