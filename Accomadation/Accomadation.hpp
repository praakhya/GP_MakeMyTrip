#include "../Place/Place.hpp"
#include "../Utils/Utils.hpp"
#include "../Guest/Guest.hpp"
#include "../Room/Room.hpp"
class Accomadation
{
    Place *place;
    int capacity;
    Address *address;
    List<Room> *rooms;
public:
    Accomadation();
};