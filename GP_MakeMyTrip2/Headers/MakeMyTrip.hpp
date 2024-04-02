#include <iostream>
#include <string>
#include <unistd.h>

#include "Utils.hpp"
#include "menu.hpp"
#include "HotelInterface.hpp"
#include "HotelEndpoint.hpp"
#include "HomestayRepository.hpp"
#include "HotelRepository.hpp"
#include "VillaRepository.hpp"

class MakeMyTrip {
  void runCustomer();
  void runAdmin();
  int runMenu();
  Map<std::string, VoidFunctionPointer> *choices;


public:
  static void executeMenu(const Map<std::string, VoidFunctionPointer> &menu);
  MakeMyTrip();
  void run();
  void startHotelBooking();
  void startHomestayBooking() {}
  void startVillaBooking() {}
  void startAccomodation();
  void startTransportation() {}
  void startManager() {}
};
