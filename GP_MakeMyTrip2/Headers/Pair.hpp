#ifndef __PAIR_HPP__
#define __PAIR_HPP__

#include <iostream>

template <typename A, typename B>
class Pair
{
    friend std::ostream& operator<<(std::ostream& strm,
                                    const Pair<A, B>& rhs) {
        strm << '{' << rhs.k << ':' << rhs.v << '}';
        return strm;
    }
    A k;
    B v;

public:
    Pair()
    {
    }
    Pair(const Pair& rhs)
    : Pair(rhs.k, rhs.v)
    {

    }
    Pair(const A& key, const B& value)
    : k(key),
      v(value)
    {
    }
    const A& key() const {
        return k;
    }
    B value() const {
        return v;
    }
    void print() {
        std::cout << *this;
    }
    Pair<A,B>* clone() {
        return new Pair<A, B>(k, v);
    }
};

#endif