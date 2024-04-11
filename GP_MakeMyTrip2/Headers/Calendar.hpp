#ifndef __CALENDAR_HPP__
#define __CALENDAR_HPP__

#include "Vector.hpp"

enum month{
    jan=1,
    feb=2,
    mar=3,
    apr=4,
    may=5,
    jun=6,
    jul=7,
    aug=8,
    sep=9,
    oct=10,
    nov=11,
    dec=12
};
class Calendar {
    private:
    Vector<unsigned long> calendar;
    unsigned long int initArray = 0x8000000000000000;
    public:
    Calendar()
     : calendar(0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00) {
    }
    unsigned long getMonth(month m) {
        return calendar[m];
    }
    bool isAvailableInRange(month m, int startD, int endD) {
        int i;
        for (i=startD; i<=endD; ++i) {
            if (!isAvailable(m,i)) {
                return false;
            }
        }
        return true;
    }
    bool isAvailable(month m, int d) {
        unsigned long int currM = getMonth(m);
        unsigned long int day = initArray >> d;
        return (currM&day)==0;
    }
    void bookDay(month m, int d) {
        unsigned long int currM = getMonth(m);
        unsigned long int day = initArray >> d;
        calendar[m] = currM|day;
    }
    void bookRange(month m, int d1, int d2) {
        for (int i=d1; i<=d2; ++i) {
            bookDay(m,i);
        }
    }
    void freeDay(month m, int d) {
        unsigned long int currM = getMonth(m);
        unsigned long int day = initArray >> d;
        calendar[m] = currM&(!day);
    }
    void freeRange(month m, int d1, int d2) {
        for (int i=d1; i<=d2; ++i) {
            freeDay(m,i);
        }
    }
};

#endif