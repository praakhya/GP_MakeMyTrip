#ifndef __HOTEL_INTERFACE_H__
#define __HOTEL_INTERFACE_H__
#include "Utils.hpp"
#include "Room.hpp"
#include "Hotel.hpp"
#include "menu.hpp"
#include "Map.hpp"
#include "HotelRepository.hpp"
#include "UserRepository.hpp"
#include <cstdlib>

class HotelInterface {
    Vector<Hotel> hotels;
    HotelRepository* hotelRepository;
    UserRepository* userRepository;
    private:
    void searchHotel();
    void searchHotelByName();
    void searchHotelByAddress();
    void searchHotelByAvailability();
    void viewHotels();
    void addHotel();
    void removeHotel();
    void runCustomer();
    void runAdmin();

    public:
    HotelInterface();
    void run();

    
};

#endif