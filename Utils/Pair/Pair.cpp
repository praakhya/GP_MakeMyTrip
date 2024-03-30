#include "../Utils.hpp"
template <typename A, typename B>
Pair<A,B>::Pair(){
    key = NULL;
    value = NULL;
}

template <typename A, typename B>
Pair<A,B>::Pair(A key, B value){
    this->key = &key;
    this->value = &value;
}