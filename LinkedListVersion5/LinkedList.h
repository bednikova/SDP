#include <iostream>
#include <fstream>

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

template <class T>
class LinkedList
{
    public:
        LinkedList() : head(NULL), tail(NULL) {}

        LinkedList(const LinkedList& l)
        {
            copy(l);
        }

        LinkedList& operator=(const LinkedList& l)
        {
            if(this != &l)
            {
                copy(l);
            }
            return *this;
        }

        ~LinkedList()
        {
            Node* n;
            while(head != NULL)
            {
                n = head;
                head = head->link;
                delete n;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const LinkedList& l)
        {
            Node* n = l.head;
            while(n != NULL)
            {
                os << n->data << " ";
                n = n->link;
            }
            os << std::endl;
            return os;
        }

        void insertFront(const T& e)
        {
            Node* n = new Node(e, head);
            head = n;
            if(tail == NULL)
            {
                tail = n;
            }
        }

        void insertEnd(const T& e)
        {
            Node* n = new Node(e, NULL);

            if(head == NULL)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->link = n;
                tail = n;

            }
        }

        void removeFront()
        {
            if(head == NULL)
            {
                throw "Linked list is empty";
            }
            Node* n;
            n = head;
            head = head->link;
            delete n;

        }
    private:

        void copy(const LinkedList& l)
        {
            head = l.head;
            tail = l.tail;
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
