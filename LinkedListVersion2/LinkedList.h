#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

template <class T>
class LinkedList
{
    public:
        LinkedList() : tos(NULL) {}

        LinkedList(const LinkedList& list)
        {
            tos = list.tos;
        }

        LinkedList& operator=(const LinkedList& list)
        {
            if(this != &list)
            {
                tos = list.tos;
            }

            return *this;
        }

        ~LinkedList()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

        void push(const T& element)
        {
            Node* node = new Node(element, tos);
            tos = node;
        }

        void pop()
        {
            Node* node = tos;
            tos = tos->link;
            delete node;
        }

        const T& top() const
        {
            return tos->data;
        }

        bool isEmpty() const
        {
            return !tos;
        }
    private:

        struct Node
        {
            T data;
            Node* link;

            Node(const T& data, Node* link) : data(data), link(link) {}
        };

        Node* tos;

};

#endif
