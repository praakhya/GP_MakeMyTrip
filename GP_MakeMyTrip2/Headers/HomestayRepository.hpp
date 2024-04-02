#include "AccomodationRepository.hpp"
#include "Homestay.hpp"

#ifndef __HOMESTAY_REPOSITORY_H__
#define __HOMESTAY_REPOSITORY_H__

class HomestayRepository : public AccomodationRepository<Homestay> {
    public:
    static HomestayRepository* instance = NULL;
    Homestay put(Homestay hotel);
    void remove(Homestay hotel);
    Homestay add(Homestay hotel);
    Homestay getByName(std::string name);
    Homestay getByAddress(std::string address);
    Homestay getByAvailability();
    static HomestayRepository* getInstance();
    private:
    HomestayRepository(){}
};

#endif