#include "Villa.hpp"
#include "Comparator.h"

int Villa::maxId = 0;
std::ostream &
operator<<(std::ostream &strm, const Villa &rhs)
{
  std::cout << rhs.id << ": ";
  rhs.printInline(strm);
  return strm;
}
void Villa::print() {
  std::cout << "ID: " << id << std::endl;
  Accomodation::print();
}
