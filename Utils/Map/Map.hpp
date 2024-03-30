#include "../Utils.hpp"
const int MAX_MAP_SIZE = 1000;
template <typename A, typename B>
class Map
{
    Pair<A, B> *pairs;
    int beginIndex;
    int endIndex;
    int length()
    {
        return endIndex - beginIndex;
    }
    void printMap() {
        for (int i=beginIndex; i<endIndex; ++i) {
            std::cout << "index = " << i << ": ";
            pairs[i].print();
            std::cout << "\n";
        }
    }
public:
    Map()
    {
        this->pairs = new Pair<A, B>[MAX_MAP_SIZE];
        beginIndex = 0;
        endIndex = 0;
    };
    void print() {
        this->printMap();
    }
    Pair<A, B> *get(int i) {
        return &this->pairs[i];
    }
    Pair<A, B> *begin()
    {
        return &pairs[0];
    }
    Pair<A, B> *end()
    {
        return &pairs[length() - 1];
    }
    int size()
    {
        return length();
    }
    int empty()
    {
        if (length() > 0)
        {
            return 0;
        }
        return 1;
    }
    void pair_insert(A key, B value)
    {
        this->pairs[endIndex++] = Pair<A, B>(key, value);
    }
    void erase(const A key)
    {
        int foundIndex = -1;
        for (int i = 0; i < this->length(); ++i)
        {
            if (this->pairs[i].key() == key)
            {
                foundIndex = i;
                break;
            }
        }
        if (foundIndex != -1)
        {
            for (int i = foundIndex; i < this->length() - 1; ++i)
            {
                this->pairs[i] = this->pairs[i + 1];
            }
        }
        --endIndex;
    }
};