#include "../Accomodation/Accomodation.hpp"

template <Accomodation T>
class BookingInterface {
    virtual List<Room> findAccomodation(const Date& from, const Date& to) = 0;
}