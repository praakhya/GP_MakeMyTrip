#ifndef __ACCOMODATION_INTERFACE_HPP__
#define __ACCOMODATION_INTERFACE_HPP__
#include "Utils.hpp"
#include "Room.hpp"
#include "Accomodation.hpp"
#include "menu.hpp"
#include "Map.hpp"
#include "AccomodationRepository.hpp"
#include "UserRepository.hpp"
#include <cstdlib>

template <class T>
class AccomodationInterface {
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
    AccomodationRepository<T>* accomodationRepository;
    UserRepository* userRepository;
    std::string accomName;
    void run();

};

#endif