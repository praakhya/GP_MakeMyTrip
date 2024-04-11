#include "Place.hpp"

Place::Place(const std::string &city,
             const std::string &state,
             const std::string &country)
    : city(city),
      state(state),
      country(country)
{
}
std::ostream &operator<<(std::ostream &strm, const Place &rhs)
{
    std::cout << "{";
    std::cout << "city: " << rhs.city << ", state: " << rhs.state << ", country: " << rhs.country;
    std::cout << "}";
    return strm;
}