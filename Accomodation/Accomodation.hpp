#include "../Place/Place.hpp"
#include "../Utils/Utils.hpp"
#include "../Guest/Guest.hpp"
#include "../Room/Room.hpp"
class Accomodation
{
    Place *place;
    int capacity;
    Address *address;
    List<Room> *rooms;
public:
    Accomodation();
    virtual List<Room> find(const Date& from, const Date& to) = 0;
};