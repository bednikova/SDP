#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue
{
    public:
        Queue() : arr(NULL), capacity(0), begin(0), end(0) {}

        Queue(const Queue& q)
        {
            copy(q);
        }

        Queue& operator=(const Queue& q)
        {
            if(this != &q)
            {
                delete [] arr;
                copy(q);
            }
            return *this;
        }

        ~Queue()
        {
            while(!isEmpty())
            {
                dequeue();
            }
        }

        void dequeue()
        {
            T element = first();
            begin = begin + 1;
        }

        void enqueue(const T& element)
        {
            if(isFull())
            {
                resize(capacity ? capacity*2 : 2);
            }
            arr[end] = element;
            end = end + 1;
        }

        const T& first() const
        {
            if(isEmpty())
            {
                throw "Queue is empty";
            }
            return arr[begin];
        }

        bool isEmpty() const
        {
            return begin == end;
        }

        bool isFull() const
        {
            return capacity == 0 || end == capacity;
        }

    private:
        void copy(const Queue& q)
        {
            arr = new T[q.capacity];
            for(int i = 0; i < q.capacity; ++i)
            {
                arr[i] = q.arr[i];
            }
            capacity = q.capacity;
            begin = q.begin;
            end = q.end;
        }

        void resize(int newCapacity)
        {
            T* buff = new T[newCapacity];
            for(int i = 0; i < capacity; ++i)
            {
                buff[i] = arr[i];
            }
            delete [] arr;
            arr = buff;
            capacity = newCapacity;
        }

        T* arr;
        int capacity;
        int begin;
        int end;

};

#endif
