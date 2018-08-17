//Queue implement with struct

#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__

template <class T>
class LinkedQueue
{
    public:
        LinkedQueue() : head(NULL), tail(NULL) {}

        LinkedQueue(const LinkedQueue& q)
        {
            copy(q);
        }

        LinkedQueue& operator=(const LinkedQueue& q)
        {
            if(this != &q)
            {
                copy(q);
            }
            return *this;
        }

        ~LinkedQueue()
        {
            while(!isEmpty())
            {
                dequeue();
            }
        }

        void dequeue()
        {
            if(!isEmpty())
            {
                Node* node = head;
                head = head->link;
                delete node;
            }
            else
            {
                throw "Linked Queue is empty";
            }
        }

        void enqueue(const T& element)
        {
            Node* node = new Node(element, NULL);
            if(tail == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->link = node;
                tail = node;
            }
        }

        bool isEmpty() const
        {
            return !head;
        }

        const T& first() const
        {
            if(!isEmpty())
            {
                return head->data;
            }
            else
            {
                throw "Linked Queue is empty";
            }
        }

    private:

        void copy(const LinkedQueue& q)
        {
            head = q.head;
            tail = q.tail;
        }


        struct Node
        {
            T data;
            Node* link;

            Node(const T& data, Node* link) : data(data), link(link) {}
        };

        Node* head;
        Node* tail;

};

#endif
