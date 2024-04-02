#include "Place.hpp"
#include "Room.hpp"
class Accomodation {
    std::string name;
    Place place;
    std::string address;
    Map<Room, int> rooms;
    public:
    Accomodation(
                const std::string& name,
                const Place& place,
                const std::string& address,
                const Map<Room, int>& rooms)
                : name(name), 
                place(place),
                address(address),
                rooms(rooms) {
    }
    Accomodation() {
        
    }
    Accomodation(const Accomodation& rhs) 
    :   name(rhs.name),
        place(rhs.place),
        address(rhs.address),
        rooms(rhs.rooms) {
            
        }
};