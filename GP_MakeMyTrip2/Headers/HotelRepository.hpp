#ifndef __HOTEL_REPOSITORY_H__
#define __HOTEL_REPOSITORY_H__

#include "AccomodationRepository.hpp"
#include "Hotel.hpp"
#include "Utils.hpp"


class HotelRepository : public AccomodationRepository<Hotel> {
    public:
    static HotelRepository* instance;
    static HotelRepository* getInstance();
    Hotel* getRoomById(int id);
    private:
    void load();
    HotelRepository();
    int getIndex(int id);
};

#endif