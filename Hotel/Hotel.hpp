#include "../Accomodation/Accomodation.hpp"
#include "../Utils/Utils.hpp"

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