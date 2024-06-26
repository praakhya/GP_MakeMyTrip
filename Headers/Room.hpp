#ifndef __ROOM_HPP__
#define __ROOM_HPP__
#include <string>
#include "Utils.hpp"
#include "Bed.hpp"

class Room {
    std::string roomType;
    float area;
    int bedCount;
    Price pricePerNight;
public:
    Room(const std::string& roomType, float area, int bedCount, int amount, const std::string& symbol="Rs.")
    : roomType(roomType),
      area(area),
      bedCount(bedCount),
      pricePerNight(Price(amount, symbol)) {

    }
    inline const std::string& getRoomType() {
        return roomType;
    }
    inline float getArea() {
        return area;
    }
    inline int getBedCount() {
        return bedCount;
    }
    inline const Price& getPricePerNight() {
        return pricePerNight;
    }
};
#endif