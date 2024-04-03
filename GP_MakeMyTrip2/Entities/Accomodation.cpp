#include "Accomodation.hpp"

Accomodation::Accomodation(const std::string &name,
                           const Place &place,
                           const std::string &address,
                           const Map<Room, int> &rooms)
    : name(name),
      place(place),
      address(address),
      rooms(rooms)
{
}
Accomodation::Accomodation()
{
}
Accomodation::Accomodation(const Accomodation &rhs)
    : name(rhs.name),
      place(rhs.place),
      address(rhs.address),
      rooms(rhs.rooms)
{
}

void Accomodation::printInline(std::ostream &strm) const
{

  std::cout << "{";
  std::cout << "name: " << name << ", place: " << place << ", address: " << address << ", rooms: " << rooms;
  std::cout << "}";
}
std::ostream &
operator<<(std::ostream &strm, const Accomodation &rhs)
{
  rhs.printInline(strm);
  return strm;
}