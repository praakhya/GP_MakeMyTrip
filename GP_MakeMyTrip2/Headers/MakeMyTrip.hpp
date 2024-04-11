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
  int runMenu();
  Map<std::string, VoidFunctionPointer> *choices;


public:
  static void executeMenu(const Map<std::string, VoidFunctionPointer> &menu);
  MakeMyTrip();
  void run();
  void startHotelBooking();
  void startHomestayBooking();
  void startVillaBooking();
  void startAccomodation();
  void startTransportation() {}
  void startManager() {
    UserRepository* userRepository = UserRepository::getInstance();
    std::cout << "Your Bookings: - " << std::endl;
    userRepository->showAllBookings();
  }
  void initCustomer();
  void initAdmin();
};
