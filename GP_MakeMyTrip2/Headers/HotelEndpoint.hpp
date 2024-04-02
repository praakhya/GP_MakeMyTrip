#include "AccomodationEndpoint.hpp"
#include "Hotel.hpp"
class HotelEndpoint : public AccomodationEndpoint<Hotel> {
    Hotel add(Hotel accomodation);
    void remove(Hotel accomodation);
    Hotel modify(Hotel accomodation);
    Hotel getByName(Hotel accomodation);
    Hotel getByAvailability(Hotel accomodation);
    Hotel getByAddress(Hotel accomodation);
};