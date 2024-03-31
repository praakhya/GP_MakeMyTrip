#include <iostream>

template <typename A, typename B>
class Pair
{
    friend std::ostream& operator<<(std::ostream& strm,
                                    const Pair<A, B>& rhs) {
        strm << '{' 
        << (rhs.k == 0 ? "NULL" : *(rhs.k)) 
        << ':' << (rhs.v == 0 ? "NULL" : *(rhs.v)) 
        << '}';
        return strm;
    }
    A* k;
    B* v;
    void printPair() {
        if (this->k==NULL) {
            if (this->v == NULL) {
                std::cout << "[,]";
                return;
            }
            std::cout << "[, " << *(this->v) << " ]\n";
            return;
        }
        if (this->v==NULL) {
            if (this->k == NULL) {
                std::cout << "[,]";
                return;
            }
            std::cout << "[ " << *(this->k) << ",]\n";
            return;
        }
        std::cout << "[ " << *(this->k) << " , " << *(this->v) << " ]";
    }
public:
    Pair()
    {
        k = NULL;
        v = NULL;
    }
    Pair(const Pair& rhs)
    : Pair(rhs.k, rhs.v)
    {
        
    }
    Pair(A key, B value)
    {
        this->k = new A(key);
        this->v = new B(value);
    }
    const A& key() const {
        return *k;
    }
    const B& value() const {
        return *v;
    }
    void print() {
        std::cout << *this;
    }
};
