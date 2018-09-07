#include <iostream>
#include <fstream>

using namespace std;

#ifndef __LIST_H__
#define __LIST_H__
template <class T>
class List
{
    public:
        List() : h(NULL), t(NULL) {}
        List(const List& l)
        {
            copy(l);
        }
        List& operator=(const List& l)
        {
            if(this != &l)
            {
                copy(l);
            }
            return *this;
        }
        ~List()
        {
            Node* n;
            while(h)
            {
                n = h;
                h = h->next;
                delete n;
            }
        }
        void insertFront(const T& x)
        {
            Node* n = new Node(x, h);
            h = n;
            if(!t)
            {
                t = n;
            }
        }
        void insertEnd(const T& x)
        {
            Node* n = new Node(x, NULL);
            if(!h)
            {
                h = n;
                t = n;
            }
            else
            {
                t->next = n;
                t = n;
            }
        }

        void removeFront()
        {
            Node* n = h;
            if(!h)
                throw "empty";
            h = h->next;
            delete n;

        }

        friend ostream& operator<<(ostream& os, const List& l)
        {
            Node* t = l.h;
            while(t)
            {
                os << t->data << " ";
                t = t->next;
            }
            os << endl;
            return os;
        }
    private:
        void copy(const List& l)
        {
            h = l.h;
            t = l.t;
        }
        struct Node
        {
            T data;
            Node* next;
            Node(const T& data, Node* next):data(data), next(next) {}
        };

        Node* h;
        Node* t;
};
#endif
