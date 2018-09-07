#include <iostream>
#include <fstream>

using namespace std;

#ifndef __DLIST_H__
#define __DLIST_H__

template <class T>
class dList
{
    public:
        dList() : h(NULL), t(NULL), c(NULL) {}
        dList(const dList& l)
        {
            copy(l);
        }
        dList& operator=(const dList& l)
        {
            if(this != &l)
            {
                copy(l);
            }
            return *this;
        }
        ~dList()
        {
            Node* n;
            while(h)
            {
                n = h;
                h = h->next;
                delete n;
            }
        }
        void insert(const T& x)
        {
            Node* n = new Node(x, NULL, NULL);
            if(!h)
            {
                h = n;
                t = n;
                c = n;
            }
            else
            {
                n->next = c->next;
                n->prev = c;
                c->next = n;

                if(n->next)
                    n->next->prev = n;
                else
                    t = n;

                c = n;
            }
        }


        void remove()
        {
            Node* t = c;
            if(c->next && c->prev)
            {
                c->next->prev = c->prev;
                c->prev->next = c->next;
                c = c->next;

            }
            else if(!c->next && c->prev)
            {
                t = c->prev;
                c->prev->next = c->next;
                //t = c->prev;
                c = c->prev;
            }
            else if(c->next && !c->prev)
            {
                c->next->prev = c->prev;
                h = c->next;
                c = c->next;

            }

            delete t;
        }

        friend ostream& operator<<(ostream& os, const dList& l)
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
        void copy(const dList& l)
        {
            h = l.h;
            t = l.t;
            c = l.c;
        }
        struct Node
        {
            T data;
            Node* next;
            Node* prev;
            Node(const T& data, Node* next, Node* prev):data(data), next(next), prev(prev) {}
        };

        Node* h;
        Node* t;
        Node* c;
};
#endif

