#ifndef __HOTEL_INTERFACE_H__
#define __HOTEL_INTERFACE_H__
#include "Utils.hpp"
#include "Data.hpp"
#include "Hotel.hpp"
#include "menu.hpp"
#include "Map.hpp"

extern Vector<Hotel> hotelCollection;
class HotelInterface {
    Vector<Hotel> hotels;
    public:
    HotelInterface();
    void run();
    void searchHotel();
};

#endif