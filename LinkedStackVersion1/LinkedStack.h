#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

template <class T>
class LinkedStack
{
    public:
        LinkedStack() : tos(NULL) {}

        LinkedStack(const LinkedStack& l)
        {
            tos = l.tos;
        }

        LinkedStack& operator=(const LinkedStack& l)
        {
            if(this != &l)
            {
                tos = l.tos;
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

        void pop()
        {
            Node* node = tos;
            tos = tos->link;
            delete node;
        }

        void push(const T& element)
        {
            Node* node = new Node(element, tos);
            tos = node;
        }

        const T& top() const
        {
            return tos->data;
        }

        bool isEmpty() const
        {
            return tos == NULL;
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
