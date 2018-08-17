#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

template <class T>
class LinkedList
{
    public:
        LinkedList() : tos(NULL) {}

        LinkedList(const LinkedList& l)
        {
            tos = l.tos;
        }

        LinkedList& operator=(const LinkedList& l)
        {
            if(this != &l)
            {
                tos = l.tos;
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
