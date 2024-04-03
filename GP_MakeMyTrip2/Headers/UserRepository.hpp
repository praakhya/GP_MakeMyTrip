#include "Booking.hpp"
#include "Room.hpp"
#ifndef __USER_REPOSITORY_HPP__
#define __USER_REPOSITORY_HPP__
class UserRepository {
    Vector<Booking> bookings = Vector<Booking>();
    public:
    std::string username;
    std::string type;
    static int bookingId;
    static UserRepository* instance;
    Vector<Booking>& getBookings();
    void addBooking(Room room, std::string start, std::string end);
    Booking removeBooking();
    static UserRepository* getInstance();
    private:
    void load();
    UserRepository();
};
#endif