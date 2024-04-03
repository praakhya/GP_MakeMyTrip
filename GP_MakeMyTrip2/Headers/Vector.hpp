#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
const int MAX_VECTOR_SIZE = 1000;
template <class T>
class Vector
{
    T *vector = NULL;
    int beginIndex, endIndex;
    friend std::ostream &operator<<(std::ostream &strm, 
    const Vector<T> &rhs)
    {
        std::cout << "[";
        for (int i = rhs.beginIndex; i < rhs.endIndex; ++i)
        {
            std::cout << rhs.vector[i] << ' ';
        }
        std::cout << "]";
        return strm;
    }

public:
    int size()
    {
        return endIndex - beginIndex;
    }
    Vector()
    {
        if (this->vector == NULL)
        {
            this->vector = new T[MAX_VECTOR_SIZE];
            beginIndex = 0;
            endIndex = 0;
        }
    }

    Vector(T var1) : Vector()
    {
        push_back(var1);
    }
    template <typename... Types>
    Vector(T var1, Types... var2) : Vector()
    {
        push_back(var1, var2...);
    }
    template <typename... Types>
    void push_back(T a, Types... b)
    {
        this->vector[endIndex++] = a;
        if (sizeof...(b) > 0)
        {
            push_back(b...);
        }
    }
    void push_back(T a)
    {
        this->vector[endIndex++] = a;
    }
    void pop_back()
    {
        endIndex = std::max(0, endIndex - 1);
    }
    void print()
    {
        std::cout << *this << '\n';
    }
    T &operator[](int index)
    {
        return vector[index];
    }
};

template <class T>
std::ostream &operator<<(std::ostream &strm, 
                        const Vector<T> &rhs)
{
    std::cout << "[";
    for (int i = rhs.beginIndex; i < rhs.endIndex; ++i)
    {
        std::cout << rhs.vector[i] << ' ';
    }
    std::cout << "]";
    return strm;
}

#endif