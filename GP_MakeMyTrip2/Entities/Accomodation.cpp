#include "Accomodation.hpp"

Accomodation::Accomodation(const std::string &name,
                           const Place &place,
                           const std::string &address,
                           const Vector<Room> &rooms)
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

void Accomodation::print() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Place: " << place << std::endl;
  std::cout << "Address: " << address << std::endl;
  rooms.print();
}
std::ostream &
operator<<(std::ostream &strm, const Accomodation &rhs)
{
  std::cout << "{";
  std::cout << "name: " << rhs.name << ", place: " << rhs.place << ", address: " << rhs.address << ", rooms: " << rhs.rooms;
  std::cout << "}";
  return strm;
}
void Accomodation::printInline(std::ostream& strm) const {
  strm << "{";
  strm << "name: " << name << ", place: " << place << ", address: " << address << ", rooms: " << rooms;
  strm << "}"; 
}