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
                throw "Linked queue is empty";
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

        const T& first() const
        {
            if(isEmpty())
            {
                throw "Linked queue is empty";
            }
            else
            {
                return head->data;
            }
        }

        bool isEmpty() const
        {
            return !head;
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
