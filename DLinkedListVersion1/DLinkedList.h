#include <iostream>
#include <fstream>
#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

template <class T>
class DLinkedList
{
    public:
        DLinkedList() : head(NULL), tail(NULL), curr(NULL) {}

        DLinkedList(const DLinkedList& l)
        {
            copy(l);
        }

        DLinkedList& operator=(const DLinkedList& l)
        {
            if(this != &l)
            {
                copy(l);
            }
            return *this;
        }

        ~DLinkedList()
        {
            Node* node;
            while(head != NULL)
            {
                node = head;
                head = head->next;
                delete node;
            }
        }

        void insert(const T& element)
        {
            Node* node = new Node(element, NULL, NULL);
            if(head == NULL)
            {
                head = node;
                tail = node;
                curr = node;
            }
            else
            {
                curr->next = node;
                node->prev = curr;
                curr = node;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const DLinkedList& l)
        {
            Node* node = l.head;
            while(node != NULL)
            {
                os << node->data << " ";
                node = node->next;
            }
            os << std::endl;
            return os;
        }

        void remove()
        {
            Node* n = curr;
            if(curr->next && curr->prev) //t.e. sa razlichni ot NULL
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr = curr->next;
            }
            else if(curr->next && !curr->prev) // t.e. ima next i nqma prev
            {
                head = curr->next;
                curr->next->prev = curr->prev; // curr->prev == NULL ??
                curr = curr->next;
            }
            else if(!curr->next && curr->prev) // t.e. ima prev i nqma next
            {
                tail = curr->prev;
                curr->prev->next = curr->next; //curr->next == null ??
                curr = curr->prev;
            }

            delete n;
        }
    private:

        void copy(const DLinkedList& list)
        {
            head = list.head;
            tail = list.tail;
            curr = list.curr;
        }

        struct Node
        {
            T data;
            Node* next;
            Node* prev;

            Node(const T& data, Node* next, Node* prev) : data(data), next(next), prev(prev) {}
        };

        Node* head;
        Node* tail;
        Node* curr;

};

#endif