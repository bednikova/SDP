#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class Stack
{
    public:
        Stack() : arr(NULL), tos(0), capacity(0) {}

        Stack(const Stack& s)
        {
            copy(s);
        }

        Stack& operator=(const Stack& s)
        {
            if(this != &s)
            {
                delete [] arr;
                copy(s);
            }
            return *this;
        }

        ~Stack()
        {
            delete [] arr;
        }

        void push(const T& element)
        {
            checkSize();
            arr[tos++] = element;
        }

        void pop()
        {
            if(!isEmpty())
            {
                tos--;
            }
            else
            {
                throw "Stack is empty";
            }
        }

        const T& top() const
        {
            if(!isEmpty())
            {
                return arr[tos-1];
            }
            else
            {
                throw "Stack is empty";
            }
        }
    private:

        void checkSize()
        {
            if(tos == capacity)
            {
                resize(capacity ? capacity*2 : 2);
            }
        }

        void resize(int newCapacity)
        {
            T* buff = new T[newCapacity];
            for(int i = 0; i < tos; ++i)
            {
                buff[i] = arr[i];
            }
            delete [] arr;
            arr = buff;
            capacity = newCapacity;
        }

        bool isEmpty() const
        {
            return tos == 0;
        }

        void copy(const Stack& s)
        {
            arr = new T[s.tos];
            for(int i = 0; i < s.tos; ++i)
            {
                arr[i] = s.arr[i];
            }
            tos = s.tos;
            capacity = s.capacity;
        }

    private:

        T* arr;
        int tos;
        int capacity;

};
#endif

