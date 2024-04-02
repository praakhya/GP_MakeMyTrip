#ifndef __HOTEL_HPP__
#define __HOTEL_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Hotel : public Accomodation {
    public:
        Hotel() {

        }
        Hotel(const Place& place,
                const std::string& address,
                const Map<Room, int>& rooms)
                : Accomodation(place, address, rooms) {
        }
        Hotel(const Hotel& rhs)
        : Accomodation(rhs) {

        }
};

#endif