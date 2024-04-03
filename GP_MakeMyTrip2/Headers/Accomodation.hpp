#ifndef __ACCOMODATION_H__
#define __ACCOMODATION_H__

#include "Place.hpp"
#include "Utils.hpp"
#include "Room.hpp"
class Accomodation
{
    std::string name;
    Place place;
    std::string address;
    Map<Room, int> rooms;

        friend std::ostream &operator<<(std::ostream &strm, const Accomodation &rhs);

protected:
    void printInline(std::ostream& strm) const;
public:
    Accomodation(const std::string &name,
                const Place &place,
                const std::string &address,
                const Map<Room, int> &rooms);
    Accomodation();
    Accomodation(const Accomodation &rhs);
    inline const std::string& getName() {
        return name;
    }
    inline const std::string& getAddress() {
        return address;
    }
    inline const Place& getPlace() {
        return place;
    }
    inline const Map<Room,int>& getRooms() {
        return rooms;
    }
};
#endif // __ACCOMODATION_H__