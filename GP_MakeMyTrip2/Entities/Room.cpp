#include "Room.hpp"
int Room::maxId = 0;
Room::Room(){
    roomType="NULL";
    area = 0;
    bedCount =0;
    pricePerNight = 0;
}
Room::Room(const std::string& roomType,
         float area,
         int bedCount,
         int amount,
         const std::string& symbol
         )
: roomType(roomType),
    area(area),
    bedCount(bedCount),
    pricePerNight(Price(amount, symbol)),
    id(++maxId),
    calendar(Calendar()) {

}
Room::Room(const Room& rhs)
    : roomType(rhs.roomType),
      area(rhs.area),
      bedCount(rhs.bedCount),
      pricePerNight(rhs.pricePerNight),
      id(rhs.id),
      calendar(rhs.calendar){}
void Room::print() {
    std::cout << "id: " << id << std::endl;
    std::cout << "roomType: " << roomType << std::endl;
    std::cout << "area: " << area << std::endl;
    std::cout << "bedCount: " << bedCount << std::endl;
    std::cout << "pricePerNight: " << pricePerNight << std::endl;
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &strm, const Room &rhs)
{
    std::string roomType;
    float area;
    int bedCount;
    Price pricePerNight;
    std::cout << "{"
    << "id: " << rhs.id 
    << ", roomType: " << rhs.roomType 
    << ", area: " << rhs.area 
    << ", bedCount: " << rhs.bedCount
    << ", pricePerNight: " << rhs.pricePerNight
    << " }";
    return strm;
}