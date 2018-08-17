//stack with array

#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class Stack
{
    public:
        Stack() : arr(NULL), countElements(0), capacity(0) {}
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
            arr[countElements++] = element;
        }

        void pop()
        {
            if(!isEmpty())
            {
                countElements--;
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
                return arr[countElements-1];
            }
            else
            {
                throw "Stack is empty";
            }
        }

    private:

        bool isEmpty() const
        {
            return countElements == 0;
        }

        void checkSize()
        {
            if(countElements == capacity)
            {
                resize(capacity ? capacity*2 : 2);
            }
        }

        void copy(const Stack& s)
        {
            arr = new T[s.countElements];
            for(int index = 0; index < s.countElements; ++index)
            {
                arr[index] = s.arr[index];
            }

            countElements = s.countElements;
            capacity = s.capacity;
        }

        void resize(int newCapacity)
        {
            T* buff = new T[newCapacity];
            for(int index = 0; index < countElements; ++index)
            {
                buff[index] = arr[index];
            }

            delete [] arr;
            arr = buff;
            capacity = newCapacity;
        }

        T* arr;
        int countElements;
        int capacity;

};

#endif
