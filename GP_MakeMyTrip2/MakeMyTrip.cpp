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
    if (userRepository->type == "CUSTOMER") {
        this->runCustomer();
    }
    else {
        this->runAdmin();
    }
}
void MakeMyTrip::runAdmin() {
    Menu<MakeMyTrip> mainMenu(
        *this, true,
        Menu<MakeMyTrip>::PairType("Modify Accomadation",&MakeMyTrip::startAccomodation),
        Menu<MakeMyTrip>::PairType("Modify Transportation",&MakeMyTrip::startTransportation));
    mainMenu.run();
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
        *this, true,
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
    /* Map<int,int>* m = new Map<int,int>();
    std::cout << "insert 1\n";
    m->pair_insert(1,2);
    m->print();
    std::cout << "insert 3\n";
    m->pair_insert(1,3);
    m->pair_insert(1,4);
    m->pair_insert(2,5);
    m->print();
    std::cout << "erase 1\n";
    m->erase(1);
    m->print();
    m->get(0)->print();
    std::cout << "key: " <<  m->get(0)->key() << std::endl; */

}
