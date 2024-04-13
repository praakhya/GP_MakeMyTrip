#include <iostream>
#include <string>
#include <unistd.h>

#include "Utils.hpp"
#include "menu.hpp"
#include "HotelInterface.hpp"
#include "HotelRepository.hpp"
#include "HomestayInterface.hpp"
#include "HomestayRepository.hpp"
#include "VillaInterface.hpp"
#include "VillaRepository.hpp"





class MakeMyTrip {
  void runCustomer();
  void runAdmin();
  Map<std::string, VoidFunctionPointer> *choices;


public:
  MakeMyTrip();
  void run();
  void startHotelBooking();
  void startHomestayBooking();
  void startVillaBooking();
  void startAccomodation();
  void startManager();
  void initCustomer();
  void initAdmin();
};
