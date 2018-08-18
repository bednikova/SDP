#include <iostream>
#include <fstream>
#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__
template <class T>
class DLinkedList
{
    public:
        DLinkedList() : head(NULL), tail(NULL), curr(NULL) {}
        DLinkedList(const DLinkedList& list)
        {
            copy(list);
        }

        DLinkedList& operator=(const DLinkedList& list)
        {
            if(this != &list)
            {
                copy(list);
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

        friend std::ostream& operator<<(std::ostream &os, const DLinkedList& list)
        {
            Node* node = list.head;
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
                if(node->next)
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
            if(curr->next && curr->prev)
            {
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                curr = curr->next;
            }
            else if(curr->next && !curr->prev)
            {
                curr->next->prev = curr->prev;
                head = curr->next;
                curr = curr->next;
            }
            else if(!curr->next && curr->prev)
            {
                tail = curr->prev;
                curr->prev->next = curr->next;
                curr = curr->prev;
            }

            delete node;
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
