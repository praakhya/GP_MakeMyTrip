#include "HotelInterface.hpp"

HotelInterface::HotelInterface() {
    accomodationRepository = HotelRepository::getInstance();
    userRepository = UserRepository::getInstance();
    accomName = "hotel";
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
void HotelInterface::searchAll() {
    accomodationRepository->getAll().print();
}
void HotelInterface::book()
{
    searchByAvailability();
    std::string m, startDay, endDay, hotelId, roomId, confirm;
    std::cout << "----- Enter booking details -----" << std::endl;
    std::cout << "Month Number: ";
    std::getline(std::cin, m);
    std::cout << "Start day: ";
    std::getline(std::cin, startDay);
    std::cout << "End day: ";
    std::getline(std::cin, endDay);
    std::cout << "Enter "+accomName+" id: ";
    std::getline(std::cin, hotelId);
    std::cout << "Enter room id: ";
    std::getline(std::cin, roomId);
    std::cout << "Confirm booking[y/n] ? ";
    std::getline(std::cin, confirm);
    if (confirm.compare("y")==0) {
        accomodationRepository->book(static_cast<month>(stoi(m)), stoi(startDay), stoi(endDay), stoi(hotelId), stoi(roomId));
    }
}
void HotelInterface::view() {
    accomodationRepository->getAll().print();
}
void HotelInterface::edit() {
    std::string id;
    std::cout << "Enter ID of "+accomName+": ";
    std::getline(std::cin, id);
    Hotel* storedHotel = accomodationRepository->getByID(stoi(id));
    if (storedHotel==NULL) {
        std::cout << "Sorry, the "+accomName+" you requested was not found" << std::endl;
        return;
    }
    std::cout << "Enter new name (old name= " << storedHotel->name << "): ";
    std::getline(std::cin, storedHotel->name);
    std::cout << "Enter new city (old city= " << storedHotel->place.city << "): ";
    std::getline(std::cin, storedHotel->place.city);
    std::cout << "Enter new state (old state= " << storedHotel->place.state << "): ";
    std::getline(std::cin, storedHotel->place.state);
    std::cout << "Enter new country (old country= " << storedHotel->place.country << "): ";
    std::getline(std::cin, storedHotel->place.country);
    std::cout << "Enter new address (old address= " << storedHotel->address <<"): ";
    std::getline(std::cin, storedHotel->address);
    std::cout << "Rooms present: " << storedHotel->rooms << std::endl;
    std::cout << "Add rooms? [y/n] ";
    std::string ch;
    std::getline(std::cin, ch);
    while (ch=="y") {
        addRoom(storedHotel->rooms);
        std::cout << "Add rooms? [y/n] ";
        std::getline(std::cin, ch);
    }
    std::cout << "Submitting modfications: " << storedHotel << std::endl;
    if (accomodationRepository->put(*storedHotel))
    {
        std::cout << "Hotel modified successfully" <<std::endl;
    }
    else {
        std::cout << "Hotel modification failed" <<std::endl;
    }
}
void HotelInterface::addRoom(Vector<Room>& rooms) {
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
        
        for (int i=0; i<stoi(roomCount); ++i) {
            Room room = Room(
                roomType,
                std::stof(area),
                std::stoi(bedCount),
                std::stof(amount),
                symbol
            );
            rooms.push_back(room);
        }
}
void HotelInterface::add()
{
    std::string name, address, city, state, country;
    Place place = Place();
    Vector<Room> rooms = Vector<Room>();
    std::cout << "Add a "+accomName+"" <<std::endl;
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
        addRoom(rooms);
        std::cout << "Add rooms? [y/n] ";
        std::getline(std::cin, ch);
    }
    accomodationRepository->add(
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

void HotelInterface::remove()
{
    std::string id;
    std::cout << "Enter ID of "+accomName+": ";
    std::getline(std::cin, id);
    Hotel* storedHotel = accomodationRepository->getByID(stoi(id));
    if (storedHotel==NULL) {
        std::cout << "Sorry, the "+accomName+" you requested was not found" << std::endl;
        return;
    }
    accomodationRepository->remove(*storedHotel);
}

void HotelInterface::removeRoom()
{
    std::string hotelId, roomId;
    std::cout << "Enter ID of "+accomName+": ";
    std::getline(std::cin, hotelId);
    Hotel* storedHotel = accomodationRepository->getByID(stoi(hotelId));
    if (storedHotel==NULL) {
        std::cout << "Sorry, the "+accomName+" you requested was not found" << std::endl;
        return;
    }
    std::cout << "Enter ID of room: ";
    std::getline(std::cin, roomId);
    int i;
    for (i=0; i<storedHotel->rooms.size(); ++i) {
        if (storedHotel->rooms[i].id == stoi(roomId)) {
            break;
        }
    }
    if (i >= storedHotel->rooms.size()) {
        std::cout << "Sorry, the room you requested was not found" << std::endl;
        return;
    }
    storedHotel->rooms.remove(i);
    accomodationRepository->put(*storedHotel);
}

void HotelInterface::searchByName()
{
    std::string name = "";
    std::cout << "Enter "+accomName+" name: ";
    std::getline(std::cin, name);
    Vector<Hotel> foundHotels = Vector<Hotel>();
    accomodationRepository->getByName(name, foundHotels);
    foundHotels.print();
}
void HotelInterface::searchByAddress()
{
    std::string address = "";
    std::cout << "Enter "+accomName+" address: ";
    std::getline(std::cin, address);
    Vector<Hotel> foundHotels; 
    foundHotels = accomodationRepository->getByAddress(address, foundHotels);
    foundHotels.print();
}
void HotelInterface::searchByAvailability()
{
    std::string m, startDay, endDay;
    std::cout << "----- Search for "+accomName+"s -----" << std::endl;
    std::cout << "Month Number: ";
    std::getline(std::cin, m);
    std::cout << "Start day: ";
    std::getline(std::cin, startDay);
    std::cout << "End day: ";
    std::getline(std::cin, endDay);


    
    Map<Hotel, Vector<Room>>* found = accomodationRepository->getByAvailability(static_cast<month>(stoi(m)), stoi(startDay), stoi(endDay));
    std::cout << accomName+"s available on this date: -" << std::endl;
    for (int i=0; i<found->size(); ++i) {
        Pair<Hotel, Vector<Room>>* pair = found->get(i);
        std::cout << accomName+": " << pair->key().name << std::endl;
        std::cout << "Address: " << pair->key().address << std::endl;
        pair->value().print();
        std::cout << "-------------------" << std::endl;
    }
}