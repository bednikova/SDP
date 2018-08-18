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
                node =  head;
                head = head->next;
                delete node;
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
                node->next = curr->next;
                node->prev = curr;
                curr->next = node;
                if(node->next) // != NULL
                {
                    node->next->prev = node;
                }
                else
                {
                    tail = node;
                }
                curr = node;
            }
        }

        void remove()
        {
            Node* node = curr;

            if(curr->next && curr->prev) // != null
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr = curr->next;
            }
            else if(curr->next && !curr->prev) // next != null && prev == null
            {
                curr->next->prev = curr->prev; //
                head = curr->next;
                curr = curr->next;
            }
            else if(!curr->next && curr->prev) // next == null && prev != null
            {
                tail = curr->prev;
                curr->prev->next = curr->next; //
                curr = curr->prev;
            }

            delete node;
        }

    private:

        void copy(const DLinkedList& l)
        {
            head = l.head;
            tail = l.tail;
            curr = l.curr;
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
