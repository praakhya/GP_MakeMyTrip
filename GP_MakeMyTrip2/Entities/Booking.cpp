#include "Booking.hpp"

std::ostream &
operator<<(std::ostream &strm, const Booking &rhs)
{
  printf("{ id: %d, room: %s, start: %s, end: %s }",rhs.id, rhs.room, rhs.start, rhs.end);
  return strm;
}