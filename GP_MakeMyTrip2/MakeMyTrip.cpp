#include "MakeMyTrip.hpp"
#include "UserRepository.hpp"

/*
This is the main of the project. It launches the menus relevant to the application.
As will be apparent, there is a heavy use of the Menu class to aid in the menu-drivenness of the program
*/

MakeMyTrip::MakeMyTrip()
{
}
void MakeMyTrip::run() //Launches the initial login menu (the user type is chosen)
{
    UserRepository *userRepository = UserRepository::getInstance();
    std::cout << "---------Welcome to Make My Trip!---------" << std::endl;
    std::cout << userRepository->type << ": " << userRepository->username << std::endl;
    Menu<MakeMyTrip> mainMenu( //Instantiating a Menu object that takes care of menu operations
        *this, true,
        Menu<MakeMyTrip>::PairType("Login as Customer", &MakeMyTrip::initCustomer),
        Menu<MakeMyTrip>::PairType("Login as Admin", &MakeMyTrip::initAdmin));
    mainMenu.run();
    if (userRepository->type == "CUSTOMER")
    {
        this->runCustomer();
    }
    else
    {
        this->runAdmin();
    }
}
void MakeMyTrip::runAdmin() //Launch the admin menu
{
    Menu<MakeMyTrip> mainMenu(
        *this, false,
        Menu<MakeMyTrip>::PairType("Modify Accomadation", &MakeMyTrip::startAccomodation));
    mainMenu.run();
}
void MakeMyTrip::initCustomer() //Switch to a customer login
{
    UserRepository *userRepository = UserRepository::getInstance();
    userRepository->type = "CUSTOMER";
    runCustomer();
}
void MakeMyTrip::initAdmin() //Switch to an admin login
{
    UserRepository *userRepository = UserRepository::getInstance();
    userRepository->type = "ADMIN";
    runAdmin();
}

void MakeMyTrip::runCustomer() //Launch the customer menu
{
    Menu<MakeMyTrip> mainMenu(
        *this, false,
        Menu<MakeMyTrip>::PairType("Accomadation", &MakeMyTrip::startAccomodation),
        Menu<MakeMyTrip>::PairType("Manage Bookings", &MakeMyTrip::startManager));
    mainMenu.run();
}

void MakeMyTrip::startAccomodation() //Starting the accomodation menu
{

    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<MakeMyTrip> subMenu(
        *this, false,
        Menu<MakeMyTrip>::PairType("Hotel", &MakeMyTrip::startHotelBooking),
        Menu<MakeMyTrip>::PairType("Homestay",
                                   &MakeMyTrip::startHomestayBooking),
        Menu<MakeMyTrip>::PairType("Villa", &MakeMyTrip::startVillaBooking));
    subMenu.run();
}
void MakeMyTrip::startHotelBooking()
{
    HotelInterface hotelInterface;
    hotelInterface.run();
}
void MakeMyTrip::startHomestayBooking()
{
    HomestayInterface homestayInterface;
    homestayInterface.run();
}
void MakeMyTrip::startVillaBooking()
{
    VillaInterface villaInterface;
    villaInterface.run();
}
void MakeMyTrip::startManager() {
    UserRepository* userRepository = UserRepository::getInstance();
    std::cout << "Your Bookings: - " << std::endl;
    userRepository->showAllBookings();
}


int main()
{
    MakeMyTrip m = MakeMyTrip();
    m.run();
}
