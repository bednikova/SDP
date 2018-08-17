#include <iostream>
#include <fstream>

#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

template <class T>
class DynamicArray
{
    public:
        DynamicArray() : arr(NULL), size(0), capacity(0) {}

        DynamicArray(const DynamicArray& darr)
        {
            copy(darr);
        }

        DynamicArray& operator=(const DynamicArray& darr)
        {
            if(this != &darr)
            {
                delete [] arr;
                copy(darr);
            }
            return *this;
        }

        ~DynamicArray()
        {
            delete [] arr;
        }

        int getSize() const
        {
            return size;
        }

        //template <class T>
        friend std::ostream& operator<<(std::ostream& os, const DynamicArray& darr)
        {
            int sizeA = darr.getSize();
            for(int index = 0; index < sizeA; ++index)
            {
                os << darr[index] << " ";
            }
            os << std::endl;

            return os;
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

        void add(const T& element)
        {
            checkSize();
            arr[size++] = element;
        }

        void insert(int index, const T& element)
        {
            checkSize();
            for(int i = size; i >= index; --i)
            {
                arr[i] = arr[i-1];
            }
            arr[index] = element;
            size++;
        }

        void remove(int index)
        {
            if(checkIndex(index))
            {
                for(int i = index; i < size; ++i)
                {
                    arr[i] = arr[i+1];
                }
                size--;
            }
        }

        int find(const T& element)
        {
            for(int i = 0; i < size; ++i)
            {
                if(arr[i] == element)
                    return i;
            }

            return -1;
        }
    private:
        void copy(const DynamicArray& darr)
        {
            arr = new T[darr.size];
            for(int i = 0; i < darr.size; ++i)
            {
                arr[i] = darr.arr[i];
            }
            capacity = darr.capacity;
            size = darr.size;
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

        void checkSize()
        {
            if(size == capacity)
            {
                resize(capacity ? capacity*2 : 2);
            }
        }

        bool checkIndex(int index) const
        {
            return index >= 0 && index < size;
        }

        T* arr;
        int size;
        int capacity;

};

#endif
