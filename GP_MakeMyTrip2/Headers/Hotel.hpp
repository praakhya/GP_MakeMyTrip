#ifndef __HOTEL_HPP__
#define __HOTEL_HPP__

#include "Accomodation.hpp"
#include "Utils.hpp"

class Hotel : public Accomodation
{
public:
        int id;
        Hotel()
        {
          this->id = 0;
        }
        Hotel( const std::string &name,
                const Place &place,
              const std::string &address,
              const Map<Room, int> &rooms)
            : Accomodation(name, place, address, rooms)
        {
          this->id = 0;
        }
        Hotel(const Hotel &rhs)
            : Accomodation(rhs)
        {
          this->id = 0;
        }
        friend std::ostream &operator<<(std::ostream &strm, const Hotel &rhs);
};

#endif