#include "UserRepository.hpp"
#include <unistd.h>

UserRepository* UserRepository::instance = 0;
Vector<Booking> UserRepository::bookings = Vector<Booking>();
int UserRepository::bookingId = 0;


UserRepository* UserRepository::getInstance() {
    
    if (UserRepository::instance==NULL) {
        UserRepository::instance = new UserRepository();
    }
    return UserRepository::instance;
}

UserRepository::UserRepository() {
    load();
}
void UserRepository::load() {
    if (getuid()==0) {
        username = getlogin();
        type = "ADMIN";
    }
    else {
        username = getlogin();
        type = "CUSTOMER";
    }
}
void UserRepository::addBooking(const Accomodation& accom, const Room& room, const month& mnth, int start, int end) {
    bookings.push_back(Booking(
        accom, room, mnth, start, end
    ));
}
void UserRepository::showAllBookings() {
    bookings.print();
}
void UserRepository::removeBooking(int id) {
    int i;
    for (i=0; i<bookings.size(); ++i) {
        if (bookings[i].id == id) {
            break;
        }
    }
    bookings.remove(i);
}