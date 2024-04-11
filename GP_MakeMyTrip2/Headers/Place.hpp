#ifndef __PLACE_H__
#define __PLACE_H__

#include <string>
#include "Utils.hpp"

class Place
{

public:
    Place(const std::string &city = "Bengaluru",
          const std::string &state = "Karnataka",
          const std::string &country = "India");
    std::string city;
    std::string state;
    std::string country;
    const std::string &getCity();
    const std::string &getState();
    const std::string &getCountry();
    friend std::ostream &operator<<(std::ostream &strm, const Place &rhs);
};

#endif