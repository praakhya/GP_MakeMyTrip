#include "Homestay.hpp"
#include "Comparator.h"

int Homestay::maxId = 0;
std::ostream &
operator<<(std::ostream &strm, const Homestay &rhs)
{
  std::cout << rhs.id << ": ";
  rhs.printInline(strm);
  return strm;
}
void Homestay::print() {
  std::cout << "ID: " << id << std::endl;
  Accomodation::print();
}
