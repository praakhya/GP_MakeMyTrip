#include "HotelInterface.hpp"

HotelInterface::HotelInterface()
{
    hotelRepository = HotelRepository::getInstance();
    userRepository = UserRepository::getInstance();
}
void HotelInterface::run()
{
    if (userRepository->type == "CUSTOMER")
        runCustomer();
    else
        runAdmin();
}
void HotelInterface::runCustomer()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Search hotels", &HotelInterface::searchHotel));
    subMenu.run();
}
void HotelInterface::runAdmin()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Add a hotel", &HotelInterface::addHotel),
        Menu<HotelInterface>::PairType("View hotels", &HotelInterface::viewHotels)    
    );
    subMenu.run();
}

void HotelInterface::searchHotel()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Search hotel by name", &HotelInterface::searchHotelByName),
        Menu<HotelInterface>::PairType("Search hotel by address", &HotelInterface::searchHotelByAddress),
        Menu<HotelInterface>::PairType("Search hotel by availability", &HotelInterface::searchHotelByAvailability));
    subMenu.run();
}
void HotelInterface::viewHotels() {
    hotelRepository->getAll().print();
}

void HotelInterface::addHotel()
{
    std::string name, address, city, state, country;
    Place place = Place();
    Map<Room, int> rooms = Map<Room, int>();
    std::cout << "Add a hotel" <<std::endl;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter address: ";
    std::getline(std::cin, address);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state: ";
    std::getline(std::cin, state);
    std::cout << "Enter country: ";
    std::getline(std::cin, country);
    std::string ch;
    std::cout << "Add rooms? [y/n] ";
    std::getline(std::cin, ch);
    while (ch=="y") {
        std::string roomType, area, bedCount, roomCount, amount, symbol;
        std::cout << "Enter room type: ";
        std::getline(std::cin, roomType);
        std::cout << "Enter area: ";
        std::getline(std::cin, area);
        std::cout << "Enter bed count: ";
        std::getline(std::cin, bedCount);
        std::cout << "Enter price amount: ";
        std::getline(std::cin, amount);
        std::cout << "Enter price symbol: ";
        std::getline(std::cin, symbol);
        std::cout << "Enter number of rooms: ";
        std::getline(std::cin, roomCount);
        rooms.pair_insert(
            Room(
                roomType,
                std::stof(area),
                std::stoi(bedCount),
                std::stof(amount), 
                symbol
            ),
            std::stoi(roomCount)
        );
        std::cout << "Add rooms? [y/n] ";
        std::getline(std::cin, ch);
    }
    hotelRepository->add(
        Hotel(
            name,
            Place(
                city,
                state,
                country
            ),
            address,
            rooms
        )
    );
}

void HotelInterface::removeHotel()
{
    Map<std::string, VoidFunctionPointer> accomodationSubMenu;
    Menu<HotelInterface> subMenu(
        *this, false,
        Menu<HotelInterface>::PairType("Search hotel by name", &HotelInterface::searchHotelByName),
        Menu<HotelInterface>::PairType("Search hotel by address", &HotelInterface::searchHotelByAddress),
        Menu<HotelInterface>::PairType("Search hotel by availability", &HotelInterface::searchHotelByAvailability));
    subMenu.run();
}

void HotelInterface::searchHotelByName()
{
    std::string name = "";
    std::cout << "Enter hotel name: ";
    std::getline(std::cin, name);
    Vector<Hotel> foundHotels = Vector<Hotel>();
    hotelRepository->getByName(name, foundHotels);
    foundHotels.print();
}
void HotelInterface::searchHotelByAddress()
{
    std::string address = "";
    std::cout << "Enter hotel address: ";
    std::getline(std::cin, address);
    Vector<Hotel> foundHotels = hotelRepository->getByAddress(address);
    foundHotels.print();
}
void HotelInterface::searchHotelByAvailability()
{
    std::cout << "The following hotels are available: -" << std::endl;
    Vector<Hotel> foundHotels = hotelRepository->getByAvailability();
    foundHotels.print();
}