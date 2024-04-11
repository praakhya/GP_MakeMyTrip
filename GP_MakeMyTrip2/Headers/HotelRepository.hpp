#ifndef __HOTEL_REPOSITORY_H__
#define __HOTEL_REPOSITORY_H__

#include "AccomodationRepository.hpp"
#include "Hotel.hpp"
#include "Utils.hpp"
#include <sqlite3.h> 


class HotelRepository : public AccomodationRepository<Hotel> {
    public:
    static HotelRepository* instance;
    static HotelRepository* getInstance();
    Hotel* getRoomById(int id);
    private:
    void load();
    HotelRepository();
};

#endif