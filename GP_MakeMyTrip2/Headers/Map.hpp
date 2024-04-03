#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "Utils.hpp"
const int MAX_MAP_SIZE = 1000;
template <typename A, typename B>
class Map
{
    friend std::ostream &operator<<(std::ostream &strm, const Map<A, B> &rhs)
    {
        std::cout << "[ ";
        for (int i = rhs.beginIndex; i < rhs.endIndex; ++i)
        {
            std::cout << *(rhs.pairs[i]) << ',';
        }
        std::cout << " ]";
        return strm;
    }
    Pair<A, B> *pairs[MAX_MAP_SIZE];
    int beginIndex;
    int endIndex;
    int length() const
    {
        return endIndex - beginIndex;
    }
    void printMap()
    {
        for (int i = beginIndex; i < endIndex; ++i)
        {
            std::cout << "index = " << i << ": ";
            pairs[i]->print();
            std::cout << "\n";
        }
    }

public:
    Map()
    {
        beginIndex = 0;
        endIndex = 0;
    };
    Map(const Map& rhs)
    : beginIndex(rhs.beginIndex),
      endIndex(rhs.endIndex) {
        for (int i = rhs.beginIndex; i < rhs.endIndex; ++i) {
            this->pairs[i] = rhs.pairs[i]->clone();
        }
    }
    void print()
    {
        this->printMap();
    }
    Pair<A, B> *get(int i) const
    {
        return this->pairs[i];
    }
    Pair<A, B> *begin()
    {
        return pairs[0];
    }
    Pair<A, B> *end()
    {
        return pairs[length() - 1];
    }
    int size() const
    {
        return length();
    }
    int empty() const
    {
        if (length() > 0)
        {
            return 0;
        }
        return 1;
    }
    void pair_insert(A key, B value)
    {
        this->pairs[endIndex++] = new Pair<A, B>(key, value);
    }

    // Variadic function Template that takes
    // variable number of arguments and prints
    // all of them.
    void insert(const Pair<A, B>& var1){
        pair_insert(var1.key(), var1.value());
    }
    template <typename T, typename... Types>
    void insert(const T& var1, const Types& ...var2)
    {
        pair_insert(var1.key(), var1.value());
        if (sizeof...(Types)>0) {
            insert(var2...);
        }
    }
    void erase(const A key)
    {
        int foundIndex = -1;
        for (int i = 0; i < this->length(); ++i)
        {
            if (this->pairs[i]->key() == key)
            {
                foundIndex = i;
                break;
            }
        }
        if (foundIndex != -1)
        {
            delete this->pairs[foundIndex];
            for (int i = foundIndex; i < this->length() - 1; ++i)
            {
                this->pairs[i] = this->pairs[i + 1];
            }
        }
        --endIndex;
    }
};
#endif