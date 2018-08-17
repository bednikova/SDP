#ifndef __STACK_H__
#define __STACK_H__

template <class T>
class Stack
{
    public:
        Stack()  : arr(NULL), tos(0), capacity(0) {}
        Stack(const Stack& s);
        Stack& operator=(const Stack& s);
        ~Stack();

        const T& top() const;
        void pop();
        void push(const T& element);

    private:

        bool isEmpty() const;
        void resize(int newCapacity);
        void checkSize();
        void copy(const Stack& s);

    private:

        T* arr;
        int tos;
        int capacity;

};
#endif

#include "Stack.imp"
