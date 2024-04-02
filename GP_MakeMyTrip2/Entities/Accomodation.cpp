#include "Accomodation.hpp"

Accomodation::Accomodation(const Place &place,
                           const std::string &address,
                           const Map<Room, int> &rooms)
    : place(place),
      address(address),
      rooms(rooms)
{
}
Accomodation::Accomodation()
{
}
Accomodation::Accomodation(const Accomodation &rhs)
    : place(rhs.place),
      address(rhs.address),
      rooms(rhs.rooms)
{
}