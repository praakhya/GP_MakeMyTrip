#ifndef __HOMESTAY_HPP__
#define __HOMESTAY_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Homestay : public Accomodation {
    public:
        Homestay() {

        }
        Homestay(const Place& place,
                const std::string& address,
                const Map<Room, int>& rooms)
                : Accomodation(place, address, rooms) {
        }
        Homestay(const Homestay& rhs)
        : Accomodation(rhs) {

        }
};

#endif