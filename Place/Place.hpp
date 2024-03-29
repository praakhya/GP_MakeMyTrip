#include <string>
#include "../Utils/Utils.hpp"
#include "../Accomadation/Accomadation.hpp"
class Place
{
    std::string city;
    std::string state;
    std::string country;
    List<Accomadation> accomadations;
public:
    Place();
};