#include "HotelRepository.hpp"

HotelRepository::instance = 0;

Hotel HotelRepository::put(Hotel accomodation){}
void HotelRepository::remove(Hotel accomodation){}
Hotel HotelRepository::add(Hotel accomodation){}
Hotel HotelRepository::getByName(std::string name){}
Hotel HotelRepository::getByAddress(std::string address){}
Hotel HotelRepository::getByAvailability(){}
static HotelRepository* HotelRepository::getInstance() {
    if (this->instance==NULL) {
        this->instance = new HotelRepository();
    }
    return this->instance;
}

