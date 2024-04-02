#include "AccomodationRepository.hpp"
#include "Hotel.hpp"

#ifndef __HOTEL_REPOSITORY_H__
#define __HOTEL_REPOSITORY_H__

class HotelRepository : public AccomodationRepository<Hotel> {
    public:
    static HotelRepository* instance = NULL;
    Hotel put(Hotel hotel);
    void remove(Hotel hotel);
    Hotel add(Hotel hotel);
    Hotel getByName(std::string name);
    Hotel getByAddress(std::string address);
    Hotel getByAvailability();
    static HotelRepository* getInstance();
    private:
    HotelRepository(){}
};

#endif