#ifndef __HOMESTAY_HPP__
#define __HOMESTAY_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Homestay : public Accomodation
{
    static int maxId;

public:
        int id;
        Homestay()
        {
        }
        Homestay(
            const std::string &name,
              const Place &place,
              const std::string &address,
              const Vector<Room> &rooms)
            : Accomodation(name, place, address, rooms),
            id(++maxId)
        {
        }
        Homestay(const Homestay &rhs)
            : Accomodation(rhs),
            id(rhs.id)
        {
        }
        friend std::ostream &operator<<(std::ostream &strm, const Homestay &rhs);
        void print();
};

#endif