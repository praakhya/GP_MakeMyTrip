#include "VillaInterface.hpp"

VillaInterface::VillaInterface() {
    accomodationRepository = VillaRepository::getInstance();
    userRepository = UserRepository::getInstance();
    accomName = "villa";
}
void VillaInterface::runCustomer()
{
    std::cout << "------ Customer ------" << std::endl;
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<VillaInterface> subMenu(
        *this, false,
        Menu<VillaInterface>::PairType("Search "+accomName, &VillaInterface::search),
        Menu<VillaInterface>::PairType("Book "+accomName, &VillaInterface::book));
    subMenu.run();
}
void VillaInterface::runAdmin()
{
    std::cout << "------ Admin ------" << std::endl;
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<VillaInterface> subMenu(
        *this, false,
        Menu<VillaInterface>::PairType("Add a "+accomName, &VillaInterface::add),
        Menu<VillaInterface>::PairType("View "+accomName+"s", &VillaInterface::view),
        Menu<VillaInterface>::PairType("Edit "+accomName+"s", &VillaInterface::edit),
        Menu<VillaInterface>::PairType("Remove "+accomName+"s", &VillaInterface::remove),
        Menu<VillaInterface>::PairType("Remove room", &VillaInterface::removeRoom)
    );
    subMenu.run();
}

void VillaInterface::search()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<VillaInterface> subMenu(
        *this, false,
        Menu<VillaInterface>::PairType("Search "+accomName+" by name", &VillaInterface::searchByName),
        Menu<VillaInterface>::PairType("Search "+accomName+" by address", &VillaInterface::searchByAddress),
        Menu<VillaInterface>::PairType("Search "+accomName+" by availability", &VillaInterface::searchByAvailability),
        Menu<VillaInterface>::PairType("See All", &VillaInterface::searchAll));
    subMenu.run();
}





