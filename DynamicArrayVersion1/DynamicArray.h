#include <iostream>
#include <fstream>

#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

template <class T>
class DynamicArray
{
    public:
        DynamicArray() : arr(NULL), size(0), capacity(0) {}

        DynamicArray(const DynamicArray& d)
        {
            copy(d);
        }

        DynamicArray& operator=(const DynamicArray& d)
        {
            if(this != &d)
            {
                delete [] arr;
                copy(d);
            }
            return *this;
        }

        ~DynamicArray()
        {
            delete [] arr;
        }

        friend std::ostream& operator<<(std::ostream& os, const DynamicArray& d)
        {
            int sizeArray = d.size;
            for(int i = 0; i < sizeArray; ++i)
            {
                os << d.arr[i] << " ";
            }
            os << std::endl;
            return os;
        }

        void add(const T& element)
        {
            checkSize();
            arr[size++] = element;
        }

        void insert(const T& element, int index)
        {
                if(checkIndex(index))
                {
                    checkSize();
                    for(int i = size; i >= index; --i)
                    {
                        arr[i] = arr[i-1];
                    }
                    arr[index] = element;
                    size++;
                }
                else
                {
                    throw "Invalid index";
                }
        }

        int find(const T& element)
        {
            for(int i = 0; i < size; ++i)
            {
                if(arr[i] == element)
                {
                    return i;
                }
            }
            return -1;
        }

        T& operator[](int index)
        {
            if(checkIndex(index))
            {
                return arr[index];
            }
            else
            {
                throw "Invalid index";
            }
        }

        const T& operator[](int index) const
        {
            if(checkIndex(index))
            {
                return arr[index];
            }
            else
            {
                throw "Invalid index";
            }

        }
    private:
        bool checkIndex(int index)
        {
            return index >= 0 && index < size;
        }

        void checkSize()
        {
            if(size == capacity)
            {
                resize(capacity ? capacity*2 : 2);
            }
        }

        void copy(const DynamicArray& d)
        {
            arr = new T[d.size];
            for(int i = 0; i < d.size; ++i)
            {
                arr[i] = d.arr[i];
            }
            capacity = d.capacity;
            size = d.size;
        }

        void resize(int newCapacity)
        {
            T* buff = new T[newCapacity];
            for(int i = 0; i < size; ++i)
            {
                buff[i] = arr[i];
            }
            delete [] arr;
            arr = buff;
            capacity = newCapacity;
        }


        T* arr;
        int size;
        int capacity;
};

#endif
