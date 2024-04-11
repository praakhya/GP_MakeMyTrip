#include "Hotel.hpp"

int Hotel::maxId = 0;
std::ostream &
operator<<(std::ostream &strm, const Hotel &rhs)
{
  std::cout << rhs.id << ": ";
  rhs.printInline(strm);
  return strm;
}
void Hotel::print() {
  std::cout << "ID: " << id << std::endl;
  Accomodation::print();
}