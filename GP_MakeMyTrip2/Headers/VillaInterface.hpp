#ifndef __VILLA_INTERFACE_H__
#define __VILLA_INTERFACE_H__
#include "Utils.hpp"
#include "Room.hpp"
#include "Villa.hpp"
#include "menu.hpp"
#include "Map.hpp"
#include "VillaRepository.hpp"
#include "UserRepository.hpp"
#include "AccomodationInterface.hpp"
#include <cstdlib>

class VillaInterface : public AccomodationInterface<Villa> {
    private:
    void search();
    void runCustomer();
    void runAdmin();

    public:
    VillaInterface();

    
};

#endif