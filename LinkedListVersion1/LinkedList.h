#include <iostream>
#include <fstream>

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

template <class T>
class LinkedList
{
    public:
        LinkedList() : head(NULL), tail(NULL) {}

        LinkedList(const LinkedList& list)
        {
            copy(list);
        }

        LinkedList& operator=(const LinkedList& list)
        {
            if(this != &list)
            {
                copy(list);
            }
            return *this;
        }

        ~LinkedList()
        {

        }

        friend std::ostream& operator<<(std::ostream& os, const LinkedList& list)
        {
            Node* node = list.head;
            while(node != NULL)
            {
                os << node->data << " ";
                node = node->link;
            }
            os << std::endl;
            return os;
        }

        void insertFront(const T& element)
        {
            Node* node = new Node(element, head);
            head = node;
            if(tail == NULL)
            {
                tail = node;
            }
        }

        void insertEnd(const T& element)
        {
            Node* node = new Node(element, NULL);

            if(head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->link = node;
                tail = node;
            }
        }

        void removeFront()
        {
            if(head == NULL)
            {
                throw "Linked list is empty";
            }

            Node* node = head;
            head = head->link;
            delete node;
        }
    private:
        void copy(const LinkedList& list)
        {
            head = list.head;
            tail = list.tail;
        }

        struct Node
        {
            T data;
            Node* link;

            Node(const T& data, Node* link) : data(data), link(link) {}
        };

        Node* head;
        Node* tail;
};

#endif
