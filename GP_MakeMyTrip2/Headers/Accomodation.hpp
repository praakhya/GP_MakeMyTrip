#ifndef __ACCOMODATION_H__
#define __ACCOMODATION_H__

#include "Place.hpp"
#include "Utils.hpp"
#include "Room.hpp"
class Accomodation
{
    Place place;
    std::string address;
    Map<Room, int> rooms;

public:
    Accomodation(const Place &place,
                 const std::string &address,
                 const Map<Room, int> &rooms);
    Accomodation();
    Accomodation(const Accomodation &rhs);
};
#endif // __ACCOMODATION_H__