#ifndef __VILLA_HPP__
#define __VILLA_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Villa : public Accomodation {
    public:
        Villa() {

        }
        Villa(const Place& place,
                const std::string& address,
                const Map<Room, int>& rooms)
                : Accomodation(place, address, rooms) {
        }
        Villa(const Villa& rhs)
        : Accomodation(rhs) {

        }
};

#endif