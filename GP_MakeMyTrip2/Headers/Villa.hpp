#ifndef __VILLA_HPP__
#define __VILLA_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Villa : public Accomodation {
    public:
        Villa() {

        }
        Villa(const std::string& name,
                const Place& place,
                const std::string& address,
                const Map<Room, int>& rooms)
                : Accomodation(name, place, address, rooms) {
        }
        Villa(const Villa& rhs)
        : Accomodation(rhs) {

        }
};

#endif