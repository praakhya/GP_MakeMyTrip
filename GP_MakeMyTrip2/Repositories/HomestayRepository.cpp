#include "HomestayRepository.hpp"
HomestayRepository::instance = 0;
Homestay HomestayRepository::put(Homestay accomodation){}
void HomestayRepository::remove(Homestay accomodation){}
Homestay HomestayRepository::add(Homestay accomodation){}
Homestay HomestayRepository::getByName(std::string name){}
Homestay HomestayRepository::getByAddress(std::string address){}
Homestay HomestayRepository::getByAvailability(){}
static HomestayRepository* getInstance() {
    if (this->instance==NULL) {
        this->instance = new HomestayRepository();
    }
    return this->instance;
}

