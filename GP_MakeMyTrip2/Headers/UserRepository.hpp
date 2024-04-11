#ifndef __USER_REPOSITORY_HPP__
#define __USER_REPOSITORY_HPP__

#include "Accomodation.hpp"
#include "Booking.hpp"
#include "Room.hpp"
class UserRepository {
    static Vector<Booking> bookings;
    public:
    std::string username;
    std::string type;
    static int bookingId;
    static UserRepository* instance;
    Vector<Booking>& getBookings();
    void addBooking(const Accomodation& accom, const Room& room, const month& mnth, int start, int end);
    void removeBooking(int id);
    void showAllBookings();
    static UserRepository* getInstance();
    private:
    void load();
    UserRepository();
};
#endif