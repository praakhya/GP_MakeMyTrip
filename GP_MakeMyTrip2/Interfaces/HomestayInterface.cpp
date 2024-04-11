#include "HomestayInterface.hpp"

HomestayInterface::HomestayInterface() {
    accomodationRepository = HomestayRepository::getInstance();
    userRepository = UserRepository::getInstance();
    accomName = "homestay";
}
void HomestayInterface::runCustomer()
{
    std::cout << "------ Customer ------" << std::endl;
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HomestayInterface> subMenu(
        *this, false,
        Menu<HomestayInterface>::PairType("Search "+accomName, &HomestayInterface::search),
        Menu<HomestayInterface>::PairType("Book "+accomName, &HomestayInterface::book));
    subMenu.run();
}
void HomestayInterface::runAdmin()
{
    std::cout << "------ Admin ------" << std::endl;
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HomestayInterface> subMenu(
        *this, false,
        Menu<HomestayInterface>::PairType("Add a "+accomName, &HomestayInterface::add),
        Menu<HomestayInterface>::PairType("View "+accomName+"s", &HomestayInterface::view),
        Menu<HomestayInterface>::PairType("Edit "+accomName+"s", &HomestayInterface::edit),
        Menu<HomestayInterface>::PairType("Remove "+accomName+"s", &HomestayInterface::remove),
        Menu<HomestayInterface>::PairType("Remove room", &HomestayInterface::removeRoom)
    );
    subMenu.run();
}

void HomestayInterface::search()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HomestayInterface> subMenu(
        *this, false,
        Menu<HomestayInterface>::PairType("Search "+accomName+" by name", &HomestayInterface::searchByName),
        Menu<HomestayInterface>::PairType("Search "+accomName+" by address", &HomestayInterface::searchByAddress),
        Menu<HomestayInterface>::PairType("Search "+accomName+" by availability", &HomestayInterface::searchByAvailability),
        Menu<HomestayInterface>::PairType("See All", &HomestayInterface::searchAll));
    subMenu.run();
}





