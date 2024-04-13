#include "Comparator.h"
#include "Homestay.hpp"
template <>
bool compare<>(const Homestay &lhs, const int &rhs) {
  return lhs.id == rhs;
}

#include "HomestayRepository.hpp"

HomestayRepository* HomestayRepository::instance = 0;
HomestayRepository* HomestayRepository::getInstance() {
    
    if (HomestayRepository::instance==NULL) {
        HomestayRepository::instance = new HomestayRepository();
    }
    return HomestayRepository::instance;
}
HomestayRepository::HomestayRepository() {
    load();
}

void HomestayRepository::load() {
    Vector<Room> rooms;
    for (int i=0; i<5; ++i) {
        rooms.push_back(Room("King Size Deluxe Room", 12.9, 1, 4272));
    }
    
    Homestay hotel("Homestay Grand",Place("Bengaluru"), "Banshankari", rooms);
    add(
        hotel
    );
}

int 
HomestayRepository::getIndex(int id)
{

    return all.find(id);
}
