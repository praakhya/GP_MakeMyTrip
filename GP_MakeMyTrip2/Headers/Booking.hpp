#ifndef __BOOKING_HPP__
#define __BOOKING_HPP__
#include "Room.hpp"
#include "Accomodation.hpp"

class Booking {
    friend std::ostream &operator<<(std::ostream &strm, const Booking &rhs);
    static int bookingId;
    public:
    Accomodation accomodation;
    Room room;
    month mnth;
    int start, end;
    int id;
    void print();
    Booking()
    {
    }
    Booking(
        const Accomodation &accom, const Room &room, month mnth, int start, int end)
        : id(++bookingId), accomodation(accom), room(room), mnth(mnth), start(start), end(end)
    {
    }
    Booking(const Booking &rhs)
        : id(rhs.id), accomodation(rhs.accomodation), room(rhs.room), mnth(rhs.mnth), start(rhs.start), end(rhs.end)
    {
    }
};


#endif