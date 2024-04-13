#ifndef __ACCOMODATION_REPOSITORY_H__
#define __ACCOMODATION_REPOSITORY_H__

#include <regex>
#include "Utils.hpp"
#include "UserRepository.hpp"

//This repository class is a template that all accomodations 
//follow to define their repositories. 
//The repository helps in data handling.
template <class T>
class AccomodationRepository {

protected:
    Vector<T> all = Vector<T>();

public:
    virtual int put(const T& accomodation) {
        int index = getIndex(accomodation.id);
        if (index==-1) {
            return 0;
        }
        all[index] = accomodation;
        return 1;
    }
    virtual int getIndex(int id) = 0;

    virtual  T* getByID(int id) {
        int i=getIndex(id);
        if (i!=-1) {
            return &all[i];
        }
        return NULL;
    }

    virtual void remove(const T& accomodation){
        int index = getIndex(accomodation.id);
        if (index==-1) {
            return;
        }
        all.remove(index);
    }
    const T& add(const T& accomodation){
        all.push_back(accomodation);
        return accomodation;
    }
    int book(month m, int startDate, int endDate, int accomId, int roomId) {
        T* accom = getByID(accomId);
        int i;
        for (i=0; i<accom->rooms.size(); ++i) {
            if (accom->rooms[i].id == roomId) {
                if (accom->rooms[i].calendar.isAvailableInRange(m,startDate,endDate)) {
                    break;
                }
                else {
                    std::cout << "Sorry, the room you chose is not available at your chosen time." << std::endl;
                    return 0;
                }
                
            }
        }
        if (i>=accom->rooms.size()) {
            std::cout << "Sorry, the room you are searching for does not exist" << std::endl;
            return 0;
        }
        Room room = accom->rooms[i];
        room.calendar.bookRange(m, startDate, endDate);
        UserRepository* userRepository = UserRepository::getInstance();
        userRepository->addBooking(*accom, room, m, startDate, endDate);
        return 1;
    }


    const Vector<T>& getByName(const std::string& name,
                                Vector<T>& found) const {
        for (int i=0; i<all.size(); ++i) {
            if (std::regex_match (all[i].name, std::regex("(.*)("+name+")(.*)") )) {
                found.push_back(all[i]);
            }
        }
        return found;
    }
    const Vector<T>& getAll() const {
        return all;
    }

const Vector<T>& getByAddress(const std::string& address,
                            Vector<T>& found) const{
    for (int i=0; i<all.size(); ++i) {
        if (std::regex_match (all[i].address, std::regex("(.*)("+address+")(.*)") )) {
            found.push_back(all[i]);
        }
    }
    return found;
}
Map<T, Vector<Room>>* getByAvailability(month m, int  d1, int d2){
    Map<T, Vector<Room>>* available = new Map<T, Vector<Room>>();
    for (int i=0; i<all.size(); ++i) {
        T hotel = all[i];
        Vector<Room> rooms = Vector<Room>();
        for (int j=0; j<hotel.rooms.size(); ++j) {
            if (hotel.rooms[j].calendar.isAvailableInRange(m,d1,d2)) {
                rooms.push_back(hotel.rooms[j]);
            }
        }
        if (rooms.size() > 0) {
            available->pair_insert(hotel,rooms);
        }
    }
    return available;
}

};

#endif