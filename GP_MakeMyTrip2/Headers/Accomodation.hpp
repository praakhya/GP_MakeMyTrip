#ifndef __ACCOMODATION_H__
#define __ACCOMODATION_H__

#include "Place.hpp"
#include "Utils.hpp"
#include "Room.hpp"
class Accomodation
{

        friend std::ostream &operator<<(std::ostream &strm, const Accomodation &rhs);

protected:
    void printInline(std::ostream& strm) const;
public:
    std::string name;
    Place place;
    std::string address;
    Vector<Room> rooms;
    Accomodation(const std::string &name,
                const Place &place,
                const std::string &address,
                const Vector<Room> &rooms);
    Accomodation();
    Accomodation(const Accomodation &rhs);
    void print();
};
#endif