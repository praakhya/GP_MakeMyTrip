#include "Map.hpp"
template <typename A, typename B>
Map<A,B>::Map(){
    this->pairs = new Pair<A,B>[MAX_MAP_SIZE];
    beginIndex = 0;
    endIndex = 0;
};

template <typename A, typename B>
void Map<A,B>::pair_insert(A key, B value) {
    this->pairs[endIndex++] = new Pair<A,B>(key,value);
}
template <typename A, typename B>
void erase(const A key) {
    int foundIndex = -1;
    for (int i=0; i<this->length(); ++i) {
        if (this->pairs[i]->key == key) {
            this->pairs[i] = NULL;
            foundIndex = i;
            break;
        }
    }
    if (foundIndex!=-1) {
        for (int i=foundIndex; i<this->length()-1; ++i) {
            this->pairs[i] = this->pairs[i+1];
        }
    }

}
