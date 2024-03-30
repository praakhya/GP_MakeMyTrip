#include "iostream"

template <typename A, typename B>
class Pair
{
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
    Pair(A key, B value)
    {
        this->k = new A();
        this->v = new B();
        *(this->k) = key;
        *(this->v) = value;
    }
    A key() {
        return *k;
    }
    B value() {
        return *v;
    }
    void print() {
        this->printPair();
    }
};