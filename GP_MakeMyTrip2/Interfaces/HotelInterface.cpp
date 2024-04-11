#include "HotelInterface.hpp"

HotelInterface::HotelInterface() {
    accomodationRepository = HotelRepository::getInstance();
    userRepository = UserRepository::getInstance();
    accomName = "hotel";
}
void HotelInterface::runCustomer()
{
    std::cout << "------ Customer ------" << std::endl;
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Search "+accomName, &HotelInterface::search),
        Menu<HotelInterface>::PairType("Book "+accomName, &HotelInterface::book));
    subMenu.run();
}
void HotelInterface::runAdmin()
{
    std::cout << "------ Admin ------" << std::endl;
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Add a "+accomName, &HotelInterface::add),
        Menu<HotelInterface>::PairType("View "+accomName+"s", &HotelInterface::view),
        Menu<HotelInterface>::PairType("Edit "+accomName+"s", &HotelInterface::edit),
        Menu<HotelInterface>::PairType("Remove "+accomName+"s", &HotelInterface::remove),
        Menu<HotelInterface>::PairType("Remove room", &HotelInterface::removeRoom)
    );
    subMenu.run();
}

void HotelInterface::search()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Search "+accomName+" by name", &HotelInterface::searchByName),
        Menu<HotelInterface>::PairType("Search "+accomName+" by address", &HotelInterface::searchByAddress),
        Menu<HotelInterface>::PairType("Search "+accomName+" by availability", &HotelInterface::searchByAvailability),
        Menu<HotelInterface>::PairType("See All", &HotelInterface::searchAll));
    subMenu.run();
}





