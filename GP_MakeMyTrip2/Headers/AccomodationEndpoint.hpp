template <class T>
class AccomodationEndpoint {
    virtual T add(T accomodation) = 0;
    virtual void remove(T accomodation) = 0;
    virtual T modify(T accomodation) = 0;
    virtual T getByName(T accomodation) = 0;
    virtual T getByAvailability(T accomodation)  = 0;
    virtual T getByAddress(T accomodation) = 0;
};