#include <iostream>
#include <fstream>

#ifndef __DLINKEDLISTTEST_H__
#define __DLINKEDLISTTEST_H__

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
            Node* temp;
            while(head)
            {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void insert(const T& data)
        {
            Node* newNode = new Node(data, NULL, NULL);
            if(!head)
            {
                head = newNode;
                tail = newNode;
                curr = newNode;
            }
            else
            {
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next = newNode;

                if(newNode->next)
                    newNode->next->prev = newNode;
                else
                    tail = newNode;

                curr = newNode;
            }
        }

        void remove()
        {
            Node* temp = curr;

            if(curr->next && curr->prev)
            {
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                curr = curr->next;
            }
            else if(!curr->next && curr->prev)
            {
                curr->prev->next = curr->next;
                tail = curr->prev;
                curr = curr->prev;
            }
            else if(curr->next && !curr->prev)
            {
                curr->next->prev = curr->prev;
                head = curr->next;
                curr = curr->next;
            }

            delete temp;
        }

        friend std::ostream& operator<<(std::ostream& os, const DLinkedList& l)
        {
            Node* temp = l.head;
            while(temp)
            {
                os << temp->data << " ";
                temp = temp->next;
            }
            os << std::endl;
            return os;
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
