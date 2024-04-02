#ifndef __PLACE_H__
#define __PLACE_H__

#include <string>
#include "Utils.hpp"

class Place
{
    std::string city;
    std::string state;
    std::string country;
public:
    Place(const std::string& city="Bengaluru", const std::string& state="Karnataka", const std::string& country="India")
    : city(city),
      state(state),
      country(country) {
    }
    inline const std::string& getCity() {
        return city;
    }
    inline const std::string& getState() {
        return state;
    }
    inline const std::string& getCountry() {
        return country;
    }
};
#endif