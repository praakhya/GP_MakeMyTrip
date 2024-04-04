#include "Hotel.hpp"

std::ostream &
operator<<(std::ostream &strm, const Hotel &rhs)
{
  std::cout << rhs.id << ": ";
  rhs.printInline(strm);
  return strm;
}