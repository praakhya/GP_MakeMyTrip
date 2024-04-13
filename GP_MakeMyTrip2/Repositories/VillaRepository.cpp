#include "Comparator.h"
#include "Villa.hpp"
template <>
bool compare<>(const Villa &lhs, const int &rhs) {
  return lhs.id == rhs;
}
#include "VillaRepository.hpp"

VillaRepository* VillaRepository::instance = 0;
VillaRepository* VillaRepository::getInstance() {
    
    if (VillaRepository::instance==NULL) {
        VillaRepository::instance = new VillaRepository();
    }
    return VillaRepository::instance;
}
VillaRepository::VillaRepository() {
    load();
}

void VillaRepository::load() {
    Vector<Room> rooms;
    for (int i=0; i<5; ++i) {
        rooms.push_back(Room("King Size Deluxe Room", 12.9, 1, 4272));
    }
    
    Villa hotel("Villa Grand",Place("Bengaluru"), "Banshankari", rooms);
    add(
        hotel
    );
}

int 
VillaRepository::getIndex(int id)
{

    return all.find(id);
}
