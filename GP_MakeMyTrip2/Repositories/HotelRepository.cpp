#include "HotelRepository.hpp"

HotelRepository* HotelRepository::instance = 0;
int HotelRepository::hotelId = 0;
Hotel HotelRepository::put(Hotel accomodation){
    return accomodation;
}
void HotelRepository::remove(Hotel accomodation){}
Hotel HotelRepository::add(Hotel accomodation){
    accomodation.id = ++HotelRepository::hotelId;
    std::cout << accomodation << "," << HotelRepository::hotelId << std::endl;
    allHotels.push_back(accomodation);
    std::cout << allHotels << std::endl;
    return accomodation;
}

Vector<Hotel> HotelRepository::getAll() {
    return allHotels;
}

Vector<Hotel>& HotelRepository::getByName(std::string name,
                                         Vector<Hotel>& foundHotels){
    for (int i=0; i<allHotels.size(); ++i) {
        if (std::regex_match (allHotels[i].getName(), std::regex("(.*)("+name+")(.*)") )) {
            foundHotels.push_back(allHotels[i]);
        }
    }
    return foundHotels;
}
Vector<Hotel> HotelRepository::getByAddress(std::string address){
    Vector<Hotel> foundHotels = Vector<Hotel>();
    for (int i=0; i<allHotels.size(); ++i) {
        if (std::regex_match (allHotels[i].getAddress(), std::regex("(.*)("+address+")(.*)") )) {
            foundHotels.push_back(allHotels[i]);
        }
        /* if (allHotels[i].getAddress() == address) {
            
        } */
    }
    return foundHotels;
}
Vector<Hotel> HotelRepository::getByAvailability(){
    Vector<Hotel> foundHotels = Vector<Hotel>();
    return foundHotels;
}
HotelRepository* HotelRepository::getInstance() {
    
    if (HotelRepository::instance==NULL) {
        HotelRepository::instance = new HotelRepository();
    }
    return HotelRepository::instance;
}
HotelRepository::HotelRepository() {
    load();
}
void HotelRepository::load() {
    Map<Room, int> rooms;
    rooms.pair_insert(Room("King Size Deluxe Room", 12.9, 1, 4272), 5);
    Hotel hotel("Hotel Grand",Place("Bengaluru"), "Banshankari", rooms);
    add(
        hotel
    );
}