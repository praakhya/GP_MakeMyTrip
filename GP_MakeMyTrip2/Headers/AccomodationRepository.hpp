#ifndef __ACCOMODATION_REPOSITORY_H__
#define __ACCOMODATION_REPOSITORY_H__

template <class T>
class AccomodationRepository {
    virtual T put(T accomodation) = 0;
    virtual void remove(T accomodation) = 0;
    virtual T add(T accomodation) = 0;
};

#endif