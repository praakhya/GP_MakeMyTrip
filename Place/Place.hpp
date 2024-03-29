#include <string>
#include "../Utils/Utils.hpp"
#include "../Accomodation/Accomodation.hpp"
class Place
{
    std::string city;
    std::string state;
    std::string country;
    List<Accomodation> Accomodations;
public:
    Place();
};