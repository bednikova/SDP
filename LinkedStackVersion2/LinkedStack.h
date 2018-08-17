#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

template <class T>
class LinkedStack
{
    public:
        LinkedStack() : tos(NULL) {}

        LinkedStack(const LinkedStack& list)
        {
            tos = list.tos;
        }

        LinkedStack& operator=(const LinkedStack& list)
        {
            if(this != &list)
            {
                tos = list.tos;
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
