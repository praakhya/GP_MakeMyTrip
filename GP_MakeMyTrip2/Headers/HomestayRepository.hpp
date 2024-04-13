#ifndef __HOMESTAY_REPOSITORY_H__
#define __HOMESTAY_REPOSITORY_H__

#include "AccomodationRepository.hpp"
#include "Homestay.hpp"
#include "Utils.hpp"


class HomestayRepository : public AccomodationRepository<Homestay> {
    public:
    static HomestayRepository* instance;
    static HomestayRepository* getInstance();
    Homestay* getRoomById(int id);
    private:
    void load();
    HomestayRepository();
    int getIndex(int id);
};

#endif