#include <iostream>
#include <fstream>

#ifndef __LINKEDLISTTEST_H__
#define __LINKEDLISTTEST_H__

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
            Node* temp;
            while(head)
            {
                temp = head;
                head = head->link;
                delete temp;
            }
        }

        void insert(const T& data)
        {
            Node* newNode = new Node(data, head);
            head = newNode;
            if(tail == NULL)
            {
                tail = newNode;
            }

        }

        void insertEnd(const T& data)
        {
            Node* newNode = new Node(data, NULL);

            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->link = newNode;
                tail = newNode;
            }
        }

        void remove()
        {
            if(!head)
            {
                throw "Linked list is empty";
            }

            Node* temp = head;
            head = head->link;
            delete temp;
        }

        friend std::ostream& operator<<(std::ostream& os, const LinkedList& l)
        {
            Node* temp = l.head;
            while(temp)
            {
                os << temp->data << " ";
                temp = temp->link;
            }
            os << std::endl;
            return os;
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
