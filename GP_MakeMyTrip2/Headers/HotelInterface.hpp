#ifndef __HOTEL_INTERFACE_H__
#define __HOTEL_INTERFACE_H__
#include "Utils.hpp"
#include "Room.hpp"
#include "Hotel.hpp"
#include "menu.hpp"
#include "Map.hpp"
#include "HotelRepository.hpp"
#include "UserRepository.hpp"
#include "AccomodationInterface.hpp"

class HotelInterface : public AccomodationInterface<Hotel> {
    private:
    void search();
    void runCustomer();
    void runAdmin();

    public:
    HotelInterface();

    
};

#endif