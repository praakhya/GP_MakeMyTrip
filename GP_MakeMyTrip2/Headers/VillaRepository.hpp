#include "AccomodationRepository.hpp"
#include "Villa.hpp"

#ifndef __VILLA_REPOSITORY_H__
#define __VILLA_REPOSITORY_H__

class VillaRepository : public AccomodationRepository<Villa> {
    public:
    static VillaRepository* instance = NULL;
    Villa put(Villa hotel);
    void remove(Villa hotel);
    Villa add(Villa hotel);
    Villa getByName(std::string name);
    Villa getByAddress(std::string address);
    Villa getByAvailability();
    static VillaRepository* getInstance();
    private:
    VillaRepository(){}
};

#endif