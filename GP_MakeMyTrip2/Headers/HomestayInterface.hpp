#ifndef __HOMESTAY_INTERFACE_H__
#define __HOMESTAY_INTERFACE_H__
#include "Utils.hpp"
#include "Room.hpp"
#include "Homestay.hpp"
#include "menu.hpp"
#include "Map.hpp"
#include "HomestayRepository.hpp"
#include "UserRepository.hpp"
#include "AccomodationInterface.hpp"
#include <cstdlib>

class HomestayInterface : public AccomodationInterface<Homestay> {
    private:
    void search();
    void runCustomer();
    void runAdmin();

    public:
    HomestayInterface();

    
};

#endif