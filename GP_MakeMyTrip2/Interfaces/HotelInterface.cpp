#include "HotelInterface.hpp"
HotelInterface::HotelInterface() {

}
void HotelInterface::run(){
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Search hotels", &HotelInterface::searchHotel));
    subMenu.run();
}
void HotelInterface::searchHotel() {
    std::cout << "Searched" << std::endl;
}