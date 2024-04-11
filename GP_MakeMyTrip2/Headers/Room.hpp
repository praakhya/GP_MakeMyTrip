#ifndef __ROOM_HPP__
#define __ROOM_HPP__
#include <string>
#include "Utils.hpp"

class Room {
    std::string roomType;
    float area;
    int bedCount;
    Price pricePerNight;
    static int maxId;
public:
    int id;
    Calendar calendar;
    Room();
    Room(const std::string& roomType,
         float area,
         int bedCount,
         int amount,
         const std::string& symbol="Rs."
         );
    Room(const Room& rhs);
    void print();
    friend std::ostream &operator<<(std::ostream &strm, const Room &rhs);
};
#endif
