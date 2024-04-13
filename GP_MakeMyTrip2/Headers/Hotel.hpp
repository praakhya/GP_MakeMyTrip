#ifndef __HOTEL_HPP__
#define __HOTEL_HPP__

#include "Comparator.h"
#include "Accomodation.hpp"
#include "Utils.hpp"

class Hotel : public Accomodation
{
    friend bool compare<>(const Hotel &lhs, const int &rhs);
    static int maxId;

public:
        int id;
        Hotel()
        {
        }
        Hotel(
            const std::string &name,
              const Place &place,
              const std::string &address,
              const Vector<Room> &rooms)
            : Accomodation(name, place, address, rooms),
            id(++maxId)
        {
        }
        Hotel(const Hotel &rhs)
            : Accomodation(rhs),
            id(rhs.id)
        {
        }
        friend std::ostream &operator<<(std::ostream &strm, const Hotel &rhs);
        void print();
};

#endif