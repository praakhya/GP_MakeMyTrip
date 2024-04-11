#ifndef __HOMESTAY_REPOSITORY_H__
#define __HOMESTAY_REPOSITORY_H__

#include "AccomodationRepository.hpp"
#include "Homestay.hpp"
#include "Utils.hpp"
#include <sqlite3.h> 


class HomestayRepository : public AccomodationRepository<Homestay> {
    public:
    static HomestayRepository* instance;
    static HomestayRepository* getInstance();
    Homestay* getRoomById(int id);
    private:
    void load();
    HomestayRepository();
};

#endif