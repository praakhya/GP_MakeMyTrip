#include "Room.hpp"
#ifndef __BOOKING_HPP__
#define __BOOKING_HPP__
class Booking {
    friend std::ostream &operator<<(std::ostream &strm, const Booking &rhs);
    public:
    int id;
    Room room;
    std::string start;
    std::string end;
    Booking()
    {
    }
    Booking(
        const int &id, const Room &room, const std::string &start, const std::string &end)
        : id(id), room(room), start(start), end(end)
    {
    }
    Booking(const Booking &rhs)
    {
        this->id = rhs.id;
        this->room = rhs.room;
        this->start = rhs.start;
        this->end = rhs.end;
    }
};
#endif