//Stack implement with struct

#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

template <class T>
class LinkedStack
{
    public:
        LinkedStack() : tos(NULL) {}

        LinkedStack(const LinkedStack& s)
        {
            tos = s.tos;
        }

        LinkedStack& operator=(const LinkedStack& s)
        {
            if(this != &s)
            {
                tos = s.tos;
            }
            return *this;
        }

        ~LinkedStack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

        bool isEmpty()
        {
            return !tos;
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
