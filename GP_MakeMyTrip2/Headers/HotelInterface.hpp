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
#include <cstdlib>

class HotelInterface : public AccomodationInterface<Hotel> {
    private:
    void search();
    void book();
    void searchByName();
    void searchByAddress();
    void searchByAvailability();
    void searchAll();
    void view();
    void edit();
    void add();
    void remove();
    void runCustomer();
    void runAdmin();
    void addRoom(Vector<Room>&);
    void removeRoom();

    public:
    HotelInterface();
    void run();

    
};

#endif