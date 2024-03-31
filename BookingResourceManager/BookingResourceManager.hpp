#include <iostream>
#include "../Utils/Utils.hpp"
#include "../Room/Room.hpp"
#include "../Hotel/Hotel.hpp"
#include "../Accomodation/Accomodation.hpp"
#include "../Homestay/Homestay.hpp"
#include "../Villa/Villa.hpp"
#include "../Place/Place.hpp"

class BookingManagerInterface {
    private:
    BookingManagerInterface* instance = NULL;
    Vector<Hotel> hotels;
    Vector<Homestay> homestays;
    Vector<Villa> villas;
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