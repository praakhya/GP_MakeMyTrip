#ifndef __PLACE_H__
#define __PLACE_H__

#include <string>
#include "Utils.hpp"

class Place
{
private:
    std::string city;
    std::string state;
    std::string country;

public:
    Place(const std::string &city = "Bengaluru",
          const std::string &state = "Karnataka",
          const std::string &country = "India");
    const std::string &getCity();
    const std::string &getState();
    const std::string &getCountry();
    friend std::ostream &operator<<(std::ostream &strm, const Place &rhs)
    {
        std::cout << "{";
        std::cout << "city: " << rhs.city << ", state: " << rhs.state << ", country: " << rhs.country;
        std::cout << "}";
        return strm;
    }
};
inline const std::string &
Place::getCity()
{
    return city;
}
inline const std::string &
Place::getState()
{
    return state;
}
inline const std::string &
Place::getCountry()
{
    return country;
}

#endif