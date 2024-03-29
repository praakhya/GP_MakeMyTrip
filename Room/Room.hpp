#include <string>
#include "../Utils/Utils.hpp"
#include "Bed/Bed.hpp"

class Room {
    std::string type;
    float area;
    List<Bed> beds;
    Price* pricePerNight;
};