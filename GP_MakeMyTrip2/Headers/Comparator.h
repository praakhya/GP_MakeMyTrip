#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

#include <iostream>

//Compare two object T based on parameter of type K
template <typename T, typename K>
bool compare(const T &lhs, const K &rhs)
{
    return lhs == rhs;
}

#endif // __COMPARATOR_H__