#include "Place.hpp"
#include "Utils.hpp"
#include "Guest.hpp"
#include "Room.hpp"

#ifndef __ACCOMODATION_H__
#define __ACCOMODATION_H__

class Accomodation
{
    Place place;
    std::string address;
    Map<Room, int> rooms;
public:
    Accomodation(const Place& place,
                const std::string& address,
                const Map<Room, int>& rooms)
                : place(place),
                address(address),
                rooms(rooms) {
    }
    Accomodation() {
        
    }
    Accomodation(const Accomodation& rhs) 
    : place(rhs.place),
        address(rhs.address),
        rooms(rhs.rooms) {
            
        }
};
#endif