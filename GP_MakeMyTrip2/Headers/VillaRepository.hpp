#ifndef __VILLA_REPOSITORY_H__
#define __VILLA_REPOSITORY_H__

#include "AccomodationRepository.hpp"
#include "Villa.hpp"
#include "Utils.hpp"
#include <sqlite3.h> 


class VillaRepository : public AccomodationRepository<Villa> {
    public:
    static VillaRepository* instance;
    static VillaRepository* getInstance();
    Villa* getRoomById(int id);
    private:
    void load();
    VillaRepository();
};

#endif