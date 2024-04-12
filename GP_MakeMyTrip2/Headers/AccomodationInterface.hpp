#ifndef __ACCOMODATION_INTERFACE_HPP__
#define __ACCOMODATION_INTERFACE_HPP__
#include "Utils.hpp"
#include "Room.hpp"
#include "Accomodation.hpp"
#include "menu.hpp"
#include "Map.hpp"
#include "AccomodationRepository.hpp"
#include "UserRepository.hpp"
#include <cstdlib>

template <class T>
class AccomodationInterface
{
private:
    virtual void search() = 0;
    virtual void runCustomer() = 0;
    virtual void runAdmin() = 0;

public:
    AccomodationRepository<T> *accomodationRepository;
    UserRepository *userRepository;
    std::string accomName;
    void run()
    {
        if (userRepository->type == "CUSTOMER")
            runCustomer();
        else
            runAdmin();
    }
    void searchByName()
    {
        std::string name = "";
        std::cout << concat("Enter",accomName,"name:");
        std::getline(std::cin, name);
        Vector<T> found = Vector<T>();
        accomodationRepository->getByName(name, found);
        found.print();
    }
    void searchByAddress()
    {
        std::string address = "";
        std::cout << concat("Enter",accomName,"address:");
        std::getline(std::cin, address);
        Vector<T> found;
        found = accomodationRepository->getByAddress(address, found);
        found.print();
    }
    void searchByAvailability()
    {
        std::string m, startDay, endDay;
        std::cout << concat("----- Search for", accomName, "-----\n");
        std::cout << "Month Number: ";
        std::getline(std::cin, m);
        std::cout << "Start day: ";
        std::getline(std::cin, startDay);
        std::cout << "End day: ";
        std::getline(std::cin, endDay);

        Map<T, Vector<Room>> *found = accomodationRepository->getByAvailability(static_cast<month>(stoi(m)), stoi(startDay), stoi(endDay));
        std::cout << concat(accomName," available on this date: -\n");
        for (int i = 0; i < found->size(); ++i)
        {
            Pair<T, Vector<Room>> *pair = found->get(i);
            std::cout << accomName + ": " << pair->key().name << std::endl;
            std::cout << "Address: " << pair->key().address << std::endl;
            pair->value().print();
            std::cout << "-------------------" << std::endl;
        }
    }
    void removeRoom()
    {
        std::string hotelId, roomId;
        std::cout << concat("Enter ID of", accomName, ":");
        std::getline(std::cin, hotelId);
        T *stored = accomodationRepository->getByID(stoi(hotelId));
        if (stored == NULL)
        {
            std::cout << concat("Sorry, the", accomName, "you requested was not found");
            return;
        }
        std::cout << "Enter ID of room: ";
        std::getline(std::cin, roomId);
        int i;
        for (i = 0; i < stored->rooms.size(); ++i)
        {
            if (stored->rooms[i].id == stoi(roomId))
            {
                break;
            }
        }
        if (i >= stored->rooms.size())
        {
            std::cout << "Sorry, the room you requested was not found" << std::endl;
            return;
        }
        stored->rooms.remove(i);
        accomodationRepository->put(*stored);
    }
    void remove()
    {
        std::string id;
        std::cout << concat("Enter ID of",accomName,": ");
        std::getline(std::cin, id);
        T *stored = accomodationRepository->getByID(stoi(id));
        if (stored == NULL)
        {
            std::cout << concat("Sorry, the",accomName,"you requested was not found\n");
            return;
        }
        accomodationRepository->remove(*stored);
    }
    void addRoom(Vector<Room> &rooms)
    {
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

        for (int i = 0; i < stoi(roomCount); ++i)
        {
            Room room = Room(
                roomType,
                std::stof(area),
                std::stoi(bedCount),
                std::stof(amount),
                symbol);
            rooms.push_back(room);
        }
    }
    void add()
    {
        std::string name, address, city, state, country;
        Place place = Place();
        Vector<Room> rooms = Vector<Room>();
        std::cout << concat("Add a",accomName,"\n");
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
        while (ch == "y")
        {
            addRoom(rooms);
            std::cout << "Add rooms? [y/n] ";
            std::getline(std::cin, ch);
        }
        accomodationRepository->add(
            T(
                name,
                Place(
                    city,
                    state,
                    country),
                address,
                rooms));
    }

    void view()
    {
        accomodationRepository->getAll().print();
    }
    void edit()
    {
        std::string id;
        std::cout << concat("Enter ID of",accomName,": ");
        std::getline(std::cin, id);
        T *stored = accomodationRepository->getByID(stoi(id));
        if (stored == NULL)
        {
            std::cout << concat("Sorry, the",accomName,"you requested was not found");
            return;
        }
        std::cout << "Enter new name (old name= " << stored->name << "): ";
        std::getline(std::cin, stored->name);
        std::cout << "Enter new city (old city= " << stored->place.city << "): ";
        std::getline(std::cin, stored->place.city);
        std::cout << "Enter new state (old state= " << stored->place.state << "): ";
        std::getline(std::cin, stored->place.state);
        std::cout << "Enter new country (old country= " << stored->place.country << "): ";
        std::getline(std::cin, stored->place.country);
        std::cout << "Enter new address (old address= " << stored->address << "): ";
        std::getline(std::cin, stored->address);
        std::cout << "Rooms present: " << stored->rooms << std::endl;
        std::cout << "Add rooms? [y/n] ";
        std::string ch;
        std::getline(std::cin, ch);
        while (ch == "y")
        {
            addRoom(stored->rooms);
            std::cout << "Add rooms? [y/n] ";
            std::getline(std::cin, ch);
        }
        std::cout << "Submitting modfications: " << stored << std::endl;
        if (accomodationRepository->put(*stored))
        {
            std::cout << accomName + " modified successfully" << std::endl;
        }
        else
        {
            std::cout << accomName + " modification failed" << std::endl;
        }
    }
    void searchAll()
    {
        accomodationRepository->getAll().print();
    }
    void book()
    {
        std::string m, startDay, endDay, hotelId, roomId, confirm;
        std::cout << "----- Enter booking details -----" << std::endl;
        std::cout << "Month Number: ";
        std::getline(std::cin, m);
        std::cout << "Start day: ";
        std::getline(std::cin, startDay);
        std::cout << "End day: ";
        std::getline(std::cin, endDay);
        std::cout << concat("Enter",accomName,"id: ");
        std::getline(std::cin, hotelId);
        std::cout << "Enter room id: ";
        std::getline(std::cin, roomId);
        std::cout << "Confirm booking[y/n] ? ";
        std::getline(std::cin, confirm);
        if (confirm.compare("y") == 0)
        {
            accomodationRepository->book(static_cast<month>(stoi(m)), stoi(startDay), stoi(endDay), stoi(hotelId), stoi(roomId));
        }
    }
};

#endif