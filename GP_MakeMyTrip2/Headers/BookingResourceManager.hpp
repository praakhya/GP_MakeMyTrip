#include <iostream>
#include "Utils.hpp"
#include "Room.hpp"
#include "Hotel.hpp"
#include "Accomodation.hpp"
#include "Place.hpp"

class BookingManagerInterface {
    private:
    BookingManagerInterface* instance = NULL;
    Vector<Hotel> hotels;
    BookingManagerInterface(){}
    public:
    BookingManagerInterface* getInstance() {
        if (instance == NULL) {
            instance = new BookingManagerInterface();
        }
        return instance;
    }
    const Vector<Hotel>& getHotels(const Place& place,
                            const Date& from,
                            const Date& to) {
        Map<Room, int> rooms;
        rooms.pair_insert(Room("King Size Deluxe Room", 12.9, 1, 4272), 5);
        Hotel hotel(Place("Bengaluru"), "Banshankari", rooms);
        hotels.push_back(hotel);
        return hotels;
    }
    
};