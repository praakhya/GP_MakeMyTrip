#ifndef __VILLA_HPP__
#define __VILLA_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Villa : public Accomodation
{
    static int maxId;

public:
        int id;
        Villa()
        {
        }
        Villa(
            const std::string &name,
              const Place &place,
              const std::string &address,
              const Vector<Room> &rooms)
            : Accomodation(name, place, address, rooms),
            id(++maxId)
        {
        }
        Villa(const Villa &rhs)
            : Accomodation(rhs),
            id(rhs.id)
        {
        }
        friend std::ostream &operator<<(std::ostream &strm, const Villa &rhs);
        void print();
};

#endif