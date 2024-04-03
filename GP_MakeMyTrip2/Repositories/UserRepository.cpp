#include "UserRepository.hpp"
#include <unistd.h>

UserRepository* UserRepository::instance = 0;
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
void UserRepository::addBooking(Room room, std::string start, std::string end) {
    bookings.push_back(
        Booking(bookingId++, room, start, end)
    );

}
Booking UserRepository::removeBooking() {
    
}