#include "MakeMyTrip.hpp"
#include "UserRepository.hpp"

void exitApp(){exit(0);}
typedef Pair<int, std::string> IntStringPair;
MakeMyTrip::MakeMyTrip(){
}
void MakeMyTrip::run(){
    UserRepository* userRepository = UserRepository::getInstance();
    std::cout << "---------Welcome to Make My Trip!---------" << std::endl;
    std::cout << userRepository->type << ": " << userRepository->username << std::endl;
    Menu<MakeMyTrip> mainMenu(
        *this, true,
        Menu<MakeMyTrip>::PairType("Login as Customer",&MakeMyTrip::initCustomer),
        Menu<MakeMyTrip>::PairType("Login as Admin",&MakeMyTrip::initAdmin)
        );
    mainMenu.run();
    if (userRepository->type == "CUSTOMER") {
        this->runCustomer();
    }
    else {
        this->runAdmin();
    }
}
void MakeMyTrip::runAdmin() {
    Menu<MakeMyTrip> mainMenu(
        *this, false,
        Menu<MakeMyTrip>::PairType("Modify Accomadation",&MakeMyTrip::startAccomodation),
        Menu<MakeMyTrip>::PairType("Modify Transportation",&MakeMyTrip::startTransportation)
        );
    mainMenu.run();
}
void MakeMyTrip::initCustomer() {
    UserRepository* userRepository = UserRepository::getInstance();
    userRepository->type = "CUSTOMER";
    runCustomer();
}
void MakeMyTrip::initAdmin() {
    UserRepository* userRepository = UserRepository::getInstance();
    userRepository->type = "ADMIN";
    runAdmin();
}

int MakeMyTrip::runMenu() {
    int choice;
    std::cout << "Choose an option:-\n" << std::endl;
    for (int i=0; i<choices->size(); ++i) {
        std::cout << i+1 << ". " << choices->get(i)->key() << std::endl;
    }
    std::cin >> choice;
    return choice;
}
void MakeMyTrip::runCustomer() {
    Menu<MakeMyTrip> mainMenu(
        *this, false,
        Menu<MakeMyTrip>::PairType("Accomadation",&MakeMyTrip::startAccomodation),
        Menu<MakeMyTrip>::PairType("Transportation",&MakeMyTrip::startTransportation),
        Menu<MakeMyTrip>::PairType("Manage Bookings",&MakeMyTrip::startManager));
    mainMenu.run();
}

void 
MakeMyTrip::startAccomodation() {

    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<MakeMyTrip> subMenu(
        *this, false,
        Menu<MakeMyTrip>::PairType("Hotel", &MakeMyTrip::startHotelBooking),
        Menu<MakeMyTrip>::PairType("Homestay",
                                   &MakeMyTrip::startHomestayBooking),
        Menu<MakeMyTrip>::PairType("Villa", &MakeMyTrip::startVillaBooking));
    subMenu.run();
  }
void MakeMyTrip::startHotelBooking() {
    HotelInterface hotelInterface;
    hotelInterface.run();
}

int main() {
    MakeMyTrip m = MakeMyTrip();
    m.run();
}
