#include "Comparator.h"
#include "Hotel.hpp"
template <>
bool compare<>(const Hotel &lhs, const int &rhs) {
  return lhs.id == rhs;
}

#include "HotelRepository.hpp"

HotelRepository *HotelRepository::instance = 0;
HotelRepository *HotelRepository::getInstance()
{

    if (HotelRepository::instance == NULL)
    {
        HotelRepository::instance = new HotelRepository();
    }
    return HotelRepository::instance;
}
HotelRepository::HotelRepository()
{
    load();
}

void HotelRepository::load()
{
    Vector<Room> rooms;
    for (int i = 0; i < 5; ++i)
    {
        rooms.push_back(Room("King Size Deluxe Room", 12.9, 1, 4272));
    }

    Hotel hotel("Hotel Grand", Place("Bengaluru"), "Banshankari", rooms);
    add(
        hotel);
}

int 
HotelRepository::getIndex(int id)
{

    return all.find(id);
}
