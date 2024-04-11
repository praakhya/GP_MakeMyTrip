#include "Booking.hpp"
int Booking::bookingId = 0;

std::ostream &
operator<<(std::ostream &strm, const Booking &rhs)
{
  std::cout << "{ id:" << rhs.id 
  << ", staying at:" << rhs.accomodation 
  << ", room: " << rhs.room 
  << ", month: " << rhs.mnth
  << ", from: " << rhs.start << "-> to: " << rhs.end << " }";
  return strm;
}

void Booking::print()
{
  std::cout << "________________________________" << std::endl;
  std::cout << "id:" << id <<std::endl; 
  std::cout << "  staying at: " << accomodation.name <<  std::endl;
  std::cout << accomodation.address << std::endl; 
  std::cout << "  room: " << room << std::endl;
  std::cout << "  month: " << mnth << std::endl;
  std::cout << "  from: " << start << "-> to: " << end << std::endl;
  std::cout << "________________________________" << std::endl;
}