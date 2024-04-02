#include "VillaRepository.hpp"
VillaRepository::instance = 0;
Villa VillaRepository::put(Villa accomodation){}
void VillaRepository::remove(Villa accomodation){}
Villa VillaRepository::add(Villa accomodation){}
Villa VillaRepository::getByName(std::string name){}
Villa VillaRepository::getByAddress(std::string address){}
Villa VillaRepository::getByAvailability(){}
static VillaRepository* getInstance() {
    if (this->instance==NULL) {
        this->instance = new VillaRepository();
    }
    return this->instance;
}

