#include "Hotel.hpp"

std::ostream &
operator<<(std::ostream &strm, const Hotel &rhs)
{
  rhs.printInline(strm);
  return strm;
}