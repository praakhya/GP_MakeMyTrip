#include "AccomodationRepository.hpp"
#include "Hotel.hpp"
#include "Utils.hpp"
#include <regex>

#ifndef __HOTEL_REPOSITORY_H__
#define __HOTEL_REPOSITORY_H__

class HotelRepository : public AccomodationRepository<Hotel> {
    static int hotelId;
    Vector<Hotel> allHotels = Vector<Hotel>();
    public:
    static HotelRepository* instance;
    Hotel put(Hotel hotel);
    void remove(Hotel hotel);
    Hotel add(Hotel hotel);
    Vector<Hotel>& getByName(std::string name,
                            Vector<Hotel>& foundHotels);
    Vector<Hotel> getByAddress(std::string address);
    Vector<Hotel> getByAvailability();
    Vector<Hotel> getAll();
    static HotelRepository* getInstance();
    private:
    void load();
    HotelRepository();
};

#endif